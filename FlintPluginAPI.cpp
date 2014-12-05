/**********************************************************\

Auto-generated FlintPluginAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include <Poco/URI.h>
#include <Poco/Thread.h>
#include <Poco/StreamCopier.h>
#include <Poco/NumberFormatter.h>
#include <Poco/URIStreamOpener.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>

#include "FlintPluginAPI.h"
#include "FlintWebSocketAPI.h"
#include "FlintHttpRequestAPI.h"
#include "FlintXmlHttpRequestAPI.h"
#include "FlintSSDPResponderAPI.h"

#include "SimpleStreamHelper.h"

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
FlintPluginAPI::FlintPluginAPI(
        const FlintPluginPtr &plugin,
        const FB::BrowserHostPtr &host,
        boost::asio::io_service &ioService)
        : m_plugin(plugin),
          m_host(host),
          ioService_(ioService) {

    registerMethod("echo", make_method(this, &FlintPluginAPI::echo));
    registerMethod("testEvent", make_method(this, &FlintPluginAPI::testEvent));
    registerMethod("createWebSocket", make_method(this, &FlintPluginAPI::createWebSocket));
    registerMethod("createHttpRequest", make_method(this, &FlintPluginAPI::createHttpRequest));
    registerMethod("createXMLHttpRequest", make_method(this, &FlintPluginAPI::createXmlHttpRequest));
    registerMethod("createSSDPResponder", make_method(this, &FlintPluginAPI::createSSDPResponder));

    registerMethod("httpGet", make_method(this, &FlintPluginAPI::httpGet));

    // Read-write property
    registerProperty("testString",
            make_property(this,
                    &FlintPluginAPI::get_testString,
                    &FlintPluginAPI::set_testString));

    // Read-only property
    registerProperty("version",
            make_property(this,
                    &FlintPluginAPI::get_version));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant FlintPluginAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
FB::variant FlintPluginAPI::echo(const FB::variant &msg) {
    static int n(0);
    fire_echo("So far, you clicked this many times: ", n++);

    // return "foobar";
    return msg;
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FlintPluginPtr FlintPluginAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
FlintPluginPtr FlintPluginAPI::getPlugin() {
    FlintPluginPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

// Read/Write property testString
std::string FlintPluginAPI::get_testString() {
    return m_testString;
}

void FlintPluginAPI::set_testString(const std::string &val) {
    m_testString = val;
}

// Read-only property version
std::string FlintPluginAPI::get_version() {
    return FBSTRING_PLUGIN_VERSION;
}

void FlintPluginAPI::testEvent() {
    fire_test();
}

FlintWebSocketAPIPtr FlintPluginAPI::createWebSocket(const std::string &url) {
    return boost::make_shared<FlintWebSocketAPI>(m_host, url);
}

FlintHttpRequestAPIPtr FlintPluginAPI::createHttpRequest() {
    return boost::make_shared<FlintHttpRequestAPI>(m_host, boost::ref(ioService_));
}

FlintXmlHttpRequestAPIPtr FlintPluginAPI::createXmlHttpRequest() {
    return boost::make_shared<FlintXmlHttpRequestAPI>(m_host, boost::ref(ioService_));
}

FlintSSDPResponderAPIPtr FlintPluginAPI::createSSDPResponder() {
    return boost::make_shared<FlintSSDPResponderAPI>(m_host, boost::ref(ioService_));
}

void FlintPluginAPI::httpGet(const std::string &url, const FB::JSObjectPtr &callback) {
    FB::SimpleStreamHelper::AsyncGet(m_host, FB::URI::fromString(url),
            boost::bind(&FlintPluginAPI::httpCallback, this, callback, _1, _2, _3, _4));
}

void FlintPluginAPI::httpCallback(const FB::JSObjectPtr &callback, bool success,
        const FB::HeaderMap &headers, const boost::shared_array<uint8_t> &data, const size_t size) {
    FB::VariantMap outHeaders;
    for (FB::HeaderMap::const_iterator it = headers.begin(); it != headers.end(); ++it) {
        if (headers.count(it->first) > 1) {
            if (outHeaders.find(it->first) != outHeaders.end()) {
                outHeaders[it->first].cast<FB::VariantList>().push_back(it->second);
            } else {
                outHeaders[it->first] = FB::VariantList(FB::variant_list_of(it->second));
            }
        } else {
            outHeaders[it->first] = it->second;
        }
    }

    try {
        if (success) {

            std::stringstream ss;
            ss << ">>> Response Size = " << size;
            m_host->htmlLog(ss.str());

            std::string dstr(reinterpret_cast<const char *>(data.get()), size);
            callback->InvokeAsync("", FB::variant_list_of
                    (true)
                    (outHeaders)
                    (dstr)
            );
        } else {
            callback->InvokeAsync("", FB::variant_list_of(false));
        }
    } catch (const std::runtime_error &) {
        // If the plugin was destroyed,
        // perhaps by a page navigation,
        // the JSObjectPtr's (weak) host ptr is invalid,
        // and a runtime exception will happen.
    }
}
