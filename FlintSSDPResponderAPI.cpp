#include "FlintSSDPResponderAPI.h"

const int UPNP_MAX_PACKET_LEN = 1500;
const char UPNP_GROUP[] = "239.255.255.250";
const int UPNP_PORT = 1900;
const int UPNP_REPLY_PORT = 1901;
const char UPNP_ROUTER[] = "urn:schemas-upnp-org:device:InternetGatewayDevice:1";

FlintSSDPResponderAPI::FlintSSDPResponderAPI(
        const FB::BrowserHostPtr &host, boost::asio::io_service &ioService)
        : browserHost_(host),
          endpoint_(boost::asio::ip::udp::v4(), UPNP_REPLY_PORT),
          multicastEndpoint_(boost::asio::ip::address::from_string(UPNP_GROUP), UPNP_PORT),
          socket_(ioService, endpoint_.protocol()) {

    socket_.set_option(boost::asio::socket_base::receive_buffer_size(65535));
    socket_.set_option(boost::asio::socket_base::send_buffer_size(65535));
    socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));

    registerMethod("search",
            make_method(this, &FlintSSDPResponderAPI::search));
    registerMethod("setMaxResponseTime",
            make_method(this, &FlintSSDPResponderAPI::setMaxResponseTime));
    registerMethod("start",
            make_method(this, &FlintSSDPResponderAPI::start));
    registerMethod("stop",
            make_method(this, &FlintSSDPResponderAPI::stop));
}

FlintSSDPResponderAPI::~FlintSSDPResponderAPI() {
}

// Multicasts a search request for the given search target.
// According to the SSDP specification, the search target can be one of:
//              ssdp:all: Search for all devices and services.
//       upnp:rootdevice: Search for all root devices.
// a Unique Service Name: Search for a specific device or service type.
void FlintSSDPResponderAPI::search(const std::string &searchTarget) {

    // timer_.expires_from_now (boost::posix_time::seconds(5)); // 5 seconds
    // timer_.async_wait (boost::bind (&UPnP::HandleTimer, this, boost::asio::placeholders::error));

    std::stringstream ss;
    ss << "M-SEARCH * HTTP/1.1\r\n";
    ss << "HOST: " << UPNP_GROUP << ":" << UPNP_PORT << "\r\n";
    ss << "ST:" + searchTarget + "\r\n";
    ss << "MAN:\"ssdp:discover\"\r\n";
    ss << "MX:3\r\n";
    ss << "\r\n\r\n";

    auto handler = boost::bind(&FlintSSDPResponderAPI::handleReceivedFrom, this,
            boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred);

    socket_.send_to(boost::asio::buffer(ss.str()), multicastEndpoint_);
    socket_.async_receive_from(receiveBuffer_.prepare(UPNP_MAX_PACKET_LEN), senderEndpoint_, handler);
}

void FlintSSDPResponderAPI::handleReceivedFrom(const boost::system::error_code &ecode, size_t bytesTransferred) {
    std::istream receiveStream(&receiveBuffer_);

    {
        std::stringstream ss;
        ss << "-------------------------- ";
        ss << bytesTransferred;
        browserHost_->htmlLog(ss.str());
    }

    const char *p = boost::asio::buffer_cast<const char *>(receiveBuffer_.data());
    size_t sz = boost::asio::buffer_size(receiveBuffer_.data());

    {
        std::stringstream ss;
        ss << "-------------------------- ";
        ss << std::string(p, sz);
        browserHost_->htmlLog(ss.str());
    }

    browserHost_->htmlLog("--------------------------");
}

// Sets the maximum response time (in seconds) sent with search requests.
// The maximum response time must be greater than 0.
void FlintSSDPResponderAPI::setMaxResponseTime(int seconds) {
}

// Starts the SSDPResponder.
// The responder will start receiving advertisements. It will also send ssdp:alive
// messages for all registered advertisements. While the SSDPResponder is running,
// it will send periodic discovery messages (ssdp:alive) for all registered advertisements.
// Messages will be send at a random interval. The interval will be larger than
// 1/3 of the Advertisement's life time and smaller than 2/3 of the Advertisement's life time.
// The SSDPResponder will also reply to any matching search requests it receives.
void FlintSSDPResponderAPI::start() {
}

// Stops the SSDPResponder.
// The responder will send ssdp:byebye messages for all registered advertisements.
// Please note that the byebye messages will be sent using the timer, after stop() returns.
// When using an external timer, make sure that the SSDPResponder remains alive until all
// byebye messages have been sent and/or cancel all timer tasks before destroying the SSDPResponder.
void FlintSSDPResponderAPI::stop() {
}