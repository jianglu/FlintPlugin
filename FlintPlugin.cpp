/**********************************************************\

Auto-generated FlintPlugin.cpp

This file contains the auto-generated main plugin object
implementation for the FlintPlugin project

\**********************************************************/

#include "FlintPluginAPI.h"

#include <boost/asio.hpp>

#include "FlintPlugin.h"

/// @fn FlintPlugin::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void FlintPlugin::StaticInitialize() {
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FlintPlugin::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void FlintPlugin::StaticDeinitialize() {
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  FlintPlugin constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
FlintPlugin::FlintPlugin() {
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  FlintPlugin destructor.
///////////////////////////////////////////////////////////////////////////////
FlintPlugin::~FlintPlugin() {
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void FlintPlugin::onPluginReady() {
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
    holderWork_.reset(new boost::asio::io_service::work(ioService_));
    ioThread_ = boost::thread(boost::bind(&boost::asio::io_service::run, &ioService_));
    ioThread_.detach();
}

void FlintPlugin::shutdown() {
    // This will be called when it is time for the plugin to shut down;
    // any threads or anything else that may hold a shared_ptr to this
    // object should be released here so that this object can be safely
    // destroyed. This is the last point that shared_from_this and weak_ptr
    // references to this object will be valid

    // 释放 io_service
    holderWork_.reset();
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that browserHost_ is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<FlintPlugin> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr FlintPlugin::createJSAPI() {
    // browserHost_ is the BrowserHost
    return boost::make_shared<FlintPluginAPI>(FB::ptr_cast<FlintPlugin>(shared_from_this()), m_host, boost::ref(ioService_));
}

bool FlintPlugin::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *) {
    //printf("Mouse down at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool FlintPlugin::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *) {
    //printf("Mouse up at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool FlintPlugin::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *) {
    //printf("Mouse move at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool FlintPlugin::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *) {
    // The window is attached; act appropriately
    return false;
}

bool FlintPlugin::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *) {
    // The window is about to be detached; act appropriately
    return false;
}

