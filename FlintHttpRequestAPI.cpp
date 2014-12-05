//
// Created by Jiang Lu on 11/15/14.
//

#include "FlintHttpRequestAPI.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <websocketpp/uri.hpp>

using boost::asio::ip::tcp;

FlintHttpRequestAPI::FlintHttpRequestAPI(const FB::BrowserHostPtr &host,
        boost::asio::io_service &ioService)
        : host_(host), ioService_(ioService), resolver_(ioService), socket_(ioService) {

    registerMethod("open", make_method(this, &FlintHttpRequestAPI::open));

    host_->htmlLog("FlintWebSocketAPI::FlintWebSocketAPI");
}

FlintHttpRequestAPI::~FlintHttpRequestAPI() {
    host_->htmlLog("FlintWebSocketAPI::~FlintWebSocketAPI");
    socket_.close();
}

void FlintHttpRequestAPI::open(const std::string &method, const std::string &url) {
    host_->htmlLog("FlintWebSocketAPI::open " + url);

    websocketpp::uri uri(url);

    // Form the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    std::ostream request_stream(&request_);
    request_stream << "GET " << uri.get_resource() << " HTTP/1.0\r\n";
    request_stream << "Host: " << uri.get_host() << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";

    // Start an asynchronous resolve to translate the server and service names
    // into a list of endpoints.
    tcp::resolver::query query(uri.get_host(), uri.get_port_str());
    resolver_.async_resolve(query,
            boost::bind(&FlintHttpRequestAPI::handleResolve, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::iterator));
}

void FlintHttpRequestAPI::handleResolve(const boost::system::error_code &err,
        tcp::resolver::iterator endpoint_iterator) {
    if (!err) {
        // Attempt a connection to the first endpoint in the list. Each endpoint
        // will be tried until we successfully establish a connection.
        tcp::endpoint endpoint = *endpoint_iterator;
        std::cout << "endpoint -> " << endpoint.address() << ":" << endpoint.port();
        socket_.async_connect(endpoint,
                boost::bind(&FlintHttpRequestAPI::handleConnect, this,
                        boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintHttpRequestAPI::handleConnect(const boost::system::error_code &err,
        tcp::resolver::iterator endpoint_iterator) {
    if (!err) {
        // The connection was successful. Send the request.
        boost::asio::async_write(socket_, request_,
                boost::bind(&FlintHttpRequestAPI::handleWriteRequest, this,
                        boost::asio::placeholders::error));
    } else if (endpoint_iterator != tcp::resolver::iterator()) {
        // The connection failed. Try the next endpoint in the list.
        socket_.close();
        tcp::endpoint endpoint = *endpoint_iterator;
        socket_.async_connect(endpoint,
                boost::bind(&FlintHttpRequestAPI::handleConnect, this,
                        boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintHttpRequestAPI::handleWriteRequest(const boost::system::error_code &err) {
    if (!err) {
        // Read the response status line.
        boost::asio::async_read_until(socket_, response_, "\r\n",
                boost::bind(&FlintHttpRequestAPI::handleReadStatusLine, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err.message() << "\n";
    }
}

void FlintHttpRequestAPI::handleReadStatusLine(const boost::system::error_code &err) {
    if (!err) {
        // Check that response is OK.
        std::istream response_stream(&response_);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);
        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return;
        }
        if (status_code != 200) {
            std::cout << "Response returned with status code ";
            std::cout << status_code << "\n";
            return;
        }

        // Read the response headers, which are terminated by a blank line.
        boost::asio::async_read_until(socket_, response_, "\r\n\r\n",
                boost::bind(&FlintHttpRequestAPI::handleReadHeaders, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err << "\n";
    }
}

void FlintHttpRequestAPI::handleReadHeaders(const boost::system::error_code &err) {
    if (!err) {
        // Process the response headers.
        std::istream response_stream(&response_);
        std::string header;
        while (std::getline(response_stream, header) && header != "\r") {
            std::cout << header << "\n";
        }
        std::cout << "\n";

        // Write whatever content we already have to output.
        if (response_.size() > 0)
            std::cout << &response_;

        // Start reading remaining data until EOF.
        boost::asio::async_read(socket_, response_,
                boost::asio::transfer_at_least(1),
                boost::bind(&FlintHttpRequestAPI::handleReadContent, this,
                        boost::asio::placeholders::error));
    } else {
        std::cout << "Error: " << err << "\n";
    }
}

void FlintHttpRequestAPI::handleReadContent(const boost::system::error_code &err) {
    if (!err) {
        // Write all of the data that has been read so far.
        std::cout << &response_;

        // Continue reading remaining data until EOF.
        boost::asio::async_read(socket_, response_,
                boost::asio::transfer_at_least(1),
                boost::bind(&FlintHttpRequestAPI::handleReadContent, this,
                        boost::asio::placeholders::error));
    } else if (err != boost::asio::error::eof) {
        std::cout << "Error: " << err << "\n";
    }
}