/**********************************************************\

Auto-generated FlintPluginAPI.h

\**********************************************************/

#ifndef H_FlintPluginAPI
#define H_FlintPluginAPI

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include <boost/asio.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "FlintPlugin.h"
#include "SimpleStreamHelper.h"

FB_FORWARD_PTR(FlintWebSocketAPI)

FB_FORWARD_PTR(FlintHttpRequestAPI)

FB_FORWARD_PTR(FlintXmlHttpRequestAPI)

FB_FORWARD_PTR(FlintSSDPResponderAPI)

class FlintPluginAPI : public FB::JSAPIAuto {
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn FlintPluginAPI::FlintPluginAPI(const FlintPluginPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    FlintPluginAPI(const FlintPluginPtr &plugin, const FB::BrowserHostPtr &host, boost::asio::io_service &ioService);

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn FlintPluginAPI::~FlintPluginAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~FlintPluginAPI() {
    }

    FlintPluginPtr getPlugin();

    FlintWebSocketAPIPtr createWebSocket(const std::string &url);

    FlintHttpRequestAPIPtr createHttpRequest();

    FlintXmlHttpRequestAPIPtr createXmlHttpRequest();

    FlintSSDPResponderAPIPtr createSSDPResponder();

    void httpGet(const std::string &url, const FB::JSObjectPtr &callback);

    void httpCallback(const FB::JSObjectPtr &callback, bool success,
            const FB::HeaderMap &headers, const boost::shared_array<uint8_t> &data, const size_t size);

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();

    void set_testString(const std::string &val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant &msg);

    // Event helpers
    FB_JSAPI_EVENT(test, 0, ());

    FB_JSAPI_EVENT(echo, 2, (const FB::variant&, const int));

    // Method test-event
    void testEvent();

private:
    FlintPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    boost::asio::io_service &ioService_;

    std::string m_testString;
};

#endif // H_FlintPluginAPI

