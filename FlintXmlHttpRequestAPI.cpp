//
// Created by Jiang Lu on 11/17/14.
//

#include "FlintXmlHttpRequestAPI.h"

#include <boost/algorithm/string.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>

using namespace boost::archive::iterators;

FlintXmlHttpRequestAPI::FlintXmlHttpRequestAPI(const FB::BrowserHostPtr &host, boost::asio::io_service &ioService)
        : browserHost_(host),
          resolver_(ioService),
          socket_(ioService),
          url_("") {

    browserHost_->htmlLog(__PRETTY_FUNCTION__);

    // Note that there is both a getter and a setter passed to make_property!
    registerMethod("getReadyState",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetReadyState));

    registerMethod("getOnReadyStateChangeCallback",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetOnReadyStateChangeCallback));

    registerMethod("setOnReadyStateChangeCallback",
            make_method(this, &FlintXmlHttpRequestAPI::jsSetOnReadyStateChangeCallback));

    registerMethod("getStatus",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetStatus));

    registerMethod("getStatusText",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetStatusText));

    registerMethod("getResponseText",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetResponseText));

    registerMethod("open",
            make_method(this, &FlintXmlHttpRequestAPI::jsOpen));

    registerMethod("send",
            make_method(this, &FlintXmlHttpRequestAPI::jsSend));

    registerMethod("abort",
            make_method(this, &FlintXmlHttpRequestAPI::jsAbort));

    registerMethod("setRequestHeader",
            make_method(this, &FlintXmlHttpRequestAPI::jsSetRequestHeader));

    registerMethod("getAllResponseHeaders",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetAllResponseHeaders));

    registerMethod("getResponseHeader",
            make_method(this, &FlintXmlHttpRequestAPI::jsGetResponseHeader));
}

FlintXmlHttpRequestAPI::~FlintXmlHttpRequestAPI() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
}

void FlintXmlHttpRequestAPI::jsOpen(const std::string &method, const std::string &url, boost::optional<bool> async) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);

    abort();
    aborted_ = false;

    // clear stuff from possible previous load
    requestHeaders_.clear();
    responseHeaders_.clear();

    changeState(Unsent);

    if (aborted_) {
        return;
    }

    method_ = boost::algorithm::to_lower_copy(method);
    url_ = websocketpp::uri(url);

    if (async) {
        async_ = *async;
    } else {
        async_ = true;
    }

    changeState(Opened);
}

void FlintXmlHttpRequestAPI::jsSend(const std::string &body) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    aborted_ = false;

    // Form the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    std::ostream request_stream(&requestBuf_);

    request_stream << "GET " << url_.get_resource() << " HTTP/1.1\r\n";
    request_stream << "Host: " << url_.get_host() << "\r\n";
    request_stream << "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:33.0) Gecko/20100101 Firefox/33.0\r\n";
    request_stream << "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
    request_stream << "Accept-Language: en-US,en;q=0.5\r\n";
    request_stream << "Accept-Encoding: gzip, deflate\r\n";
    request_stream << "Referer: " << url_.str() << "\r\n";
    request_stream << "If-Modified-Since: Thu, 13 Nov 2014 03:13:09 GMT\r\n";
    request_stream << "Cache-Control: max-age=0\r\n";

    // Custom headers
    if (requestHeaders_.size() > 0) {
        for (std::map<std::string, std::string>::iterator i = requestHeaders_.begin();
             i != requestHeaders_.end(); ++i) {
            request_stream << i->first << ": " << i->second << "\r\n";
        }
    }

    request_stream << "Connection: close\r\n\r\n";
    // request_stream << "Connection: keep-alive\r\n\r\n";

    if (method_ == "post") {
        request_stream << body;
    }

    // Start an asynchronous resolve to translate the server and service names
    // into a list of endpoints.
    tcp::resolver::query query(url_.get_host(), url_.get_port_str());
    resolver_.async_resolve(query,
            boost::bind(&FlintXmlHttpRequestAPI::handleResolve, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::iterator));
}

void FlintXmlHttpRequestAPI::jsAbort() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
}

void FlintXmlHttpRequestAPI::jsSetRequestHeader(const std::string &name, const std::string &value) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    requestHeaders_.insert(std::make_pair<std::string, std::string>(name, value));
}

std::map<std::string, std::string> FlintXmlHttpRequestAPI::jsGetAllResponseHeaders() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return responseHeaders_;
}

std::string FlintXmlHttpRequestAPI::jsGetResponseHeader(const std::string &name) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return responseHeaders_[name];
}

void FlintXmlHttpRequestAPI::handleResolve(const boost::system::error_code &err,
        tcp::resolver::iterator endpoint_iterator) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // Attempt a connection to the first endpoint in the list. Each endpoint
        // will be tried until we successfully establish a connection.
        tcp::endpoint endpoint = static_cast<tcp::endpoint>(*endpoint_iterator);
        socket_.async_connect(endpoint,
                boost::bind(&FlintXmlHttpRequestAPI::handleConnect, this,
                        boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintXmlHttpRequestAPI::handleConnect(const boost::system::error_code &err,
        tcp::resolver::iterator endpoint_iterator) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // The connection was successful. Send the request.
        boost::asio::async_write(socket_, requestBuf_,
                boost::bind(&FlintXmlHttpRequestAPI::handleWriteRequest, this,
                        boost::asio::placeholders::error));
    } else if (endpoint_iterator != tcp::resolver::iterator()) {
        // The connection failed. Try the next endpoint in the list.
        socket_.close();
        tcp::endpoint endpoint = static_cast<tcp::endpoint>(*endpoint_iterator);
        socket_.async_connect(endpoint,
                boost::bind(&FlintXmlHttpRequestAPI::handleConnect, this,
                        boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintXmlHttpRequestAPI::handleWriteRequest(const boost::system::error_code &err) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // Read the response status line. The responseBuf_ streambuf will
        // automatically grow to accommodate the entire line. The growth may be
        // limited by passing a maximum size to the streambuf constructor.
        boost::asio::async_read_until(socket_, responseBuf_, "\r\n",
                boost::bind(&FlintXmlHttpRequestAPI::handleReadStatusLine, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintXmlHttpRequestAPI::handleReadStatusLine(const boost::system::error_code &err) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // Check that response is OK.
        std::istream responseStream(&responseBuf_);

        std::string httpVersion;
        responseStream >> httpVersion;

        // statusCode;
        responseStream >> statusCode_;

        // statusText
        std::getline(responseStream, statusText_);

        if (!responseStream || httpVersion.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return;
        }

        // Read the response headers, which are terminated by a blank line.
        boost::asio::async_read_until(socket_, responseBuf_, "\r\n\r\n",
                boost::bind(&FlintXmlHttpRequestAPI::handleReadHeaders, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err << "\n";
    }
}

void FlintXmlHttpRequestAPI::handleReadHeaders(const boost::system::error_code &err) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // Process the response headers.
        std::istream responseStream(&responseBuf_);

        std::string header;
        while (std::getline(responseStream, header) && header != "\r") {
            // remove '/r'
            header.erase(std::find(header.begin(), header.end(), '\r'), header.end());

            static char const headerSeparator[] = ": ";
            auto cursor = std::search(
                    header.begin(),
                    header.end(),
                    headerSeparator,
                    headerSeparator + sizeof(headerSeparator) - 1
            );

            std::string key = std::string(header.begin(), cursor);
            std::string value = std::string(cursor + sizeof(headerSeparator) - 1, header.end());

            std::stringstream ss;
            ss << "Header: key= " << key << " value= " << value;
            browserHost_->htmlLog(ss.str());

            responseHeaders_.insert(
                    std::make_pair<std::string, std::string>(key, value));
        }

        changeState(HeadersReceived);

        // Start reading remaining data until EOF.
        boost::asio::async_read(socket_, responseBuf_,
                boost::asio::transfer_all(),
                boost::bind(&FlintXmlHttpRequestAPI::handleReadContent, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err << "\n";
    }
}

void FlintXmlHttpRequestAPI::handleReadContent(const boost::system::error_code &err) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (!err) {
        // Continue reading remaining data until EOF.
        boost::asio::async_read(socket_, responseBuf_,
                boost::asio::transfer_at_least(1),
                boost::bind(&FlintXmlHttpRequestAPI::handleReadContent, this,
                        boost::asio::placeholders::error));
        changeState(Loading);

        std::stringstream ss;
        ss << "responseBuf_.size() = " << responseBuf_.size();
        browserHost_->htmlLog(ss.str());
    } else if (err == boost::asio::error::eof) {
        changeState(Done);
    } else if (err != boost::asio::error::eof) {
        std::cout << "Error: " << err << "\n";
    } else {
        browserHost_->htmlLog("WRONG ERR CODE !");
    }
}

void FlintXmlHttpRequestAPI::abort() {
    if (socket_.is_open()) {
        socket_.close();
    }
    aborted_ = true;
}

void FlintXmlHttpRequestAPI::changeState(XMLHttpRequestState newState) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    if (state_ != newState) {
        state_ = newState;
        if (onReadyStateChangeCallback_) {
            browserHost_->htmlLog(">>> onReadyStateChangeCallback_->InvokeAsync");

            // Must in sync
            // onReadyStateChangeCallback_->InvokeAsync("", FB::variant_list_of());
            onReadyStateChangeCallback_->Invoke("", FB::variant_list_of());
        }
    }
}

// Properties
unsigned short FlintXmlHttpRequestAPI::jsGetReadyState() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return state_;
}

FB::JSObjectPtr FlintXmlHttpRequestAPI::jsGetOnReadyStateChangeCallback() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return onReadyStateChangeCallback_;
}

void FlintXmlHttpRequestAPI::jsSetOnReadyStateChangeCallback(const FB::JSObjectPtr &prop) {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    onReadyStateChangeCallback_ = prop;
}

unsigned short FlintXmlHttpRequestAPI::jsGetStatus() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return statusCode_;
}

std::string FlintXmlHttpRequestAPI::jsGetStatusText() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);
    return statusText_;
}

std::string FlintXmlHttpRequestAPI::jsGetResponseText() {
    browserHost_->htmlLog(__PRETTY_FUNCTION__);

    std::stringstream encodedStream;

    typedef base64_from_binary<
            transform_width<
                    std::istreambuf_iterator<char>, 6, 8
            >
    > base64_iterator;

    std::copy(
            base64_iterator(std::istreambuf_iterator<char>(&responseBuf_)),
            base64_iterator(std::istreambuf_iterator<char>()),
            std::ostreambuf_iterator<char>(encodedStream));

    return encodedStream.str();
}
