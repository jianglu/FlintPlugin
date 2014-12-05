//
// Created by Jiang Lu on 11/15/14.
//

#include "FlintWebSocketAPI.h"

// Bind the handlers we are using
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

FlintWebSocketAPI::FlintWebSocketAPI(
        const FB::BrowserHostPtr &host,
        const std::string &url)
        : host_(host),
          url_(url) {

    // The URL as resolved by the constructor. This is always an absolute URL. Read only.
    // Read-only property
    registerProperty("url",
            make_property(this,
                    &FlintWebSocketAPI::get_url));

    registerMethod("open", make_method(this, &FlintWebSocketAPI::open));
    registerMethod("close", make_method(this, &FlintWebSocketAPI::close));
    registerMethod("send", make_method(this, &FlintWebSocketAPI::send));

    std::cout << "FlintWebSocketAPI::FlintWebSocketAPI" << std::endl;
}

FlintWebSocketAPI::~FlintWebSocketAPI() {
    std::cout << "FlintWebSocketAPI::~FlintWebSocketAPI" << std::endl;
}

void FlintWebSocketAPI::open() {
    // set up access channels to only log interesting things
    client_.clear_access_channels(websocketpp::log::alevel::all);
    client_.set_access_channels(websocketpp::log::alevel::connect);
    client_.set_access_channels(websocketpp::log::alevel::disconnect);
    client_.set_access_channels(websocketpp::log::alevel::app);

    // Initialize the Asio transport policy
    client_.init_asio();

    client_.set_open_handler(bind(&FlintWebSocketAPI::onOpen, this, ::_1));
    client_.set_close_handler(bind(&FlintWebSocketAPI::onClose, this, ::_1));
    client_.set_fail_handler(bind(&FlintWebSocketAPI::onFail, this, ::_1));
    client_.set_message_handler(bind(&FlintWebSocketAPI::onMessage, this, ::_1, ::_2));

    websocketpp::lib::error_code ec;
    client::connection_ptr conn = client_.get_connection(url_, ec);

    // Grab a handle for this connection so we can talk to it in a thread
    // safe manor after the event loop starts.
    hdl_ = conn->get_handle();

    client_.connect(conn);

    // Create a detach thread to run the ASIO io_service event loop
    asio_thread_ = websocketpp::lib::thread(&client::run, &client_);
    asio_thread_.detach();
}

void FlintWebSocketAPI::close() {
    client_.get_io_service().post(bind(&FlintWebSocketAPI::closeImpl, this));
}

void FlintWebSocketAPI::closeImpl() {
    std::string reason = "NORMAL CLOSE";
    client_.close(hdl_, websocketpp::close::status::normal, reason);
}

void FlintWebSocketAPI::send(const std::string &message) {
    client_.get_io_service().post(bind(&FlintWebSocketAPI::sendImpl, this, std::string(message)));
}

void FlintWebSocketAPI::sendImpl(const std::string &message) {
    websocketpp::lib::error_code ec;
    client_.send(hdl_, message, websocketpp::frame::opcode::text, ec);
}

std::string FlintWebSocketAPI::get_url() {
    return url_;
}

// The open handler will signal that we are ready to start sending telemetry
void FlintWebSocketAPI::onOpen(websocketpp::connection_hdl) {
    client_.get_alog().write(websocketpp::log::alevel::app,
            "Connection opened !");

    // 触发 open 事件
    fire_open();
}

// The close handler will signal that we should stop sending telemetry
void FlintWebSocketAPI::onClose(websocketpp::connection_hdl) {
    client_.get_alog().write(websocketpp::log::alevel::app,
            "Connection closed !");

    // 触发 close 事件
    fire_close();
}

// The fail handler will signal that we should stop sending telemetry
void FlintWebSocketAPI::onFail(websocketpp::connection_hdl) {
    client_.get_alog().write(websocketpp::log::alevel::app,
            "Connection failed, stopping telemetry!");

    // 触发 error 事件
    fire_error();
}

void FlintWebSocketAPI::onMessage(websocketpp::connection_hdl hdl, message_ptr message) {
    fire_message(message->get_payload());
}
