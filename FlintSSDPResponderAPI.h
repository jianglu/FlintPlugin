#ifndef __FLINT_SSDPRESPONDERAPI_H__
#define __FLINT_SSDPRESPONDERAPI_H__

#include "JSAPIAuto.h"
#include "BrowserHost.h"

#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_array.hpp>
#include <boost/system/error_code.hpp>

class FlintSSDPResponderAPI : public FB::JSAPIAuto {
public:
    FlintSSDPResponderAPI(const FB::BrowserHostPtr &host, boost::asio::io_service &ioService);

    virtual ~FlintSSDPResponderAPI();

    // Multicasts a search request for the given search target.
    // According to the SSDP specification, the search target can be one of:
    //              ssdp:all: Search for all devices and services.
    //       upnp:rootdevice: Search for all root devices.
    // a Unique Service Name: Search for a specific device or service type.
    void search(const std::string &searchTarget);

    // Sets the maximum response time (in seconds) sent with search requests.
    // The maximum response time must be greater than 0.
    void setMaxResponseTime(int seconds);

    // Starts the SSDPResponder.
    // The responder will start receiving advertisements. It will also send ssdp:alive
    // messages for all registered advertisements. While the SSDPResponder is running,
    // it will send periodic discovery messages (ssdp:alive) for all registered advertisements.
    // Messages will be send at a random interval. The interval will be larger than
    // 1/3 of the Advertisement's life time and smaller than 2/3 of the Advertisement's life time.
    // The SSDPResponder will also reply to any matching search requests it receives.
    void start();

    // Stops the SSDPResponder.
    // The responder will send ssdp:byebye messages for all registered advertisements.
    // Please note that the byebye messages will be sent using the timer, after stop() returns.
    // When using an external timer, make sure that the SSDPResponder remains alive until all
    // byebye messages have been sent and/or cancel all timer tasks before destroying the SSDPResponder.
    void stop();

    FB_JSAPI_EVENT(serviceFound, 1, (const FB::variant&));

    FB_JSAPI_EVENT(serviceLost, 1, (const FB::variant&));

protected:
    void handleReceivedFrom(const boost::system::error_code &ecode, size_t bytes_transferred);

private:
    FB::BrowserHostPtr browserHost_;
    boost::asio::streambuf receiveBuffer_;
    boost::asio::ip::udp::endpoint endpoint_;
    boost::asio::ip::udp::endpoint multicastEndpoint_;
    boost::asio::ip::udp::endpoint senderEndpoint_;
    boost::asio::ip::udp::socket socket_;
};

#endif // __FLINT_SSDPRESPONDERAPI_H__