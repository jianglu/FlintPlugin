//
// Created by Jiang Lu on 11/17/14.
//


#ifndef __FlintXmlHttpRequestAPI_H_
#define __FlintXmlHttpRequestAPI_H_

#include "JSAPIAuto.h"
#include "BrowserHost.h"

#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_array.hpp>
#include <boost/system/error_code.hpp>
#include <websocketpp/uri.hpp>

using boost::asio::ip::tcp;
using boost::system::error_code;

// these exact numeric values are important because JS expects them
enum XMLHttpRequestState {
    Unsent = 0, // open() has not been called yet.
    Opened = 1, // send() has not been called yet.
    HeadersReceived = 2, // send() has been called, and headers and status are available.
    Loading = 3, // Downloading; responseText holds partial data.
    Done = 4 // The operation is complete.
};

class FlintXmlHttpRequestAPI : public FB::JSAPIAuto {
public:
    FlintXmlHttpRequestAPI(const FB::BrowserHostPtr &host, boost::asio::io_service &ioService);

    virtual ~FlintXmlHttpRequestAPI();

    void jsOpen(const std::string &method, const std::string &url, boost::optional<bool> async);

    void jsSend(const std::string &body);

    void jsAbort();

    void jsSetRequestHeader(const std::string &name, const std::string &value);

    std::map<std::string, std::string> jsGetAllResponseHeaders();

    std::string jsGetResponseHeader(const std::string &name);

    FB::JSObjectPtr jsGetOnReadyStateChangeCallback();

    void jsSetOnReadyStateChangeCallback(const FB::JSObjectPtr &prop);

    unsigned short jsGetReadyState();

    unsigned short jsGetStatus();

    std::string jsGetStatusText();

    std::string jsGetResponseText();

private:

    void handleResolve(const error_code &err, tcp::resolver::iterator endpoint_iterator);

    void handleConnect(const error_code &err, tcp::resolver::iterator endpoint_iterator);

    void handleWriteRequest(const error_code &err);

    void handleReadStatusLine(const error_code &err);

    void handleReadHeaders(const error_code &err);

    void handleReadContent(const error_code &err);

private:
    void abort();

    void changeState(XMLHttpRequestState newState);

private:
    FB::BrowserHostPtr browserHost_;

    tcp::resolver resolver_;
    tcp::socket socket_;
    boost::asio::streambuf requestBuf_;
    boost::asio::streambuf responseBuf_;

    bool aborted_;
    std::map<std::string, std::string> requestHeaders_;

    unsigned short statusCode_;
    std::string statusText_;

    std::map<std::string, std::string> responseHeaders_;
    std::vector<char> responseBuffer_;

    XMLHttpRequestState state_;

    std::string method_;
    websocketpp::uri url_;
    bool async_;

    FB::JSObjectPtr onReadyStateChangeCallback_;
};


#endif //__FlintXmlHttpRequestAPI_H_
