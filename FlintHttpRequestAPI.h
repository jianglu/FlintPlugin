//
// Created by Jiang Lu on 11/15/14.
//


#ifndef __FLINTHTTPREQUEST_H_
#define __FLINTHTTPREQUEST_H_

#include "JSAPIAuto.h"
#include "BrowserHost.h"

#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

using boost::asio::ip::tcp;
using boost::system::error_code;

class FlintHttpRequestAPI : public FB::JSAPIAuto {
public:
    FlintHttpRequestAPI(const FB::BrowserHostPtr &host, boost::asio::io_service &ioService);

    virtual ~FlintHttpRequestAPI();

    void open(const std::string &method, const std::string &url);

    // Events
    FB_JSAPI_EVENT(open, 0, ());

    FB_JSAPI_EVENT(message, 1, (const FB::variant&));

    FB_JSAPI_EVENT(close, 0, ());

    FB_JSAPI_EVENT(error, 0, ());

    FB_JSAPI_EVENT(http, 0, ());

    void handleResolve(const error_code &err, tcp::resolver::iterator endpoint_iterator);

    void handleConnect(const error_code &err, tcp::resolver::iterator endpoint_iterator);

    void handleWriteRequest(const error_code &err);

    void handleReadStatusLine(const error_code &err);

    void handleReadHeaders(const error_code &err);

    void handleReadContent(const error_code &err);

private:
    FB::BrowserHostPtr host_;
    boost::asio::io_service &ioService_;

    tcp::resolver resolver_;
    tcp::socket socket_;
    boost::asio::streambuf request_;
    boost::asio::streambuf response_;
};


#endif //__FLINTHTTPREQUEST_H_
