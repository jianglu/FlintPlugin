//
// Created by Jiang Lu on 11/15/14.
//


#ifndef __FlintWebSocketAPI_H_
#define __FlintWebSocketAPI_H_

#include "JSAPIAuto.h"
#include "BrowserHost.h"

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

class FlintWebSocketAPI : public FB::JSAPIAuto {
public:
    typedef websocketpp::client<websocketpp::config::asio_client> client;
    typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

    FlintWebSocketAPI(
            const FB::BrowserHostPtr &host,
            const std::string &url);

    virtual ~FlintWebSocketAPI();

    void open();

    void close();

    void closeImpl();

    void send(const std::string &message);

    void sendImpl(const std::string &message);

    // Read-only property ${PROPERTY.ident}
    std::string get_url();

    // Events
    FB_JSAPI_EVENT(open, 0, ());

    FB_JSAPI_EVENT(message, 1, (const FB::variant&));

    FB_JSAPI_EVENT(close, 0, ());

    FB_JSAPI_EVENT(error, 0, ());

protected:
    void onOpen(websocketpp::connection_hdl);

    void onClose(websocketpp::connection_hdl);

    void onFail(websocketpp::connection_hdl);

    void onMessage(websocketpp::connection_hdl hdl, message_ptr message);

private:
    FB::BrowserHostPtr host_;

    std::string url_;

    client client_;
    websocketpp::connection_hdl hdl_;
    websocketpp::lib::thread asio_thread_;
};


#endif //__FlintWebSocketAPI_H_
