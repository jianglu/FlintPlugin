#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for FlintPlugin
#
#\**********************************************************/

set(PLUGIN_NAME "FlintPlugin")
set(PLUGIN_PREFIX "FPL")
set(COMPANY_NAME "OpenFlint")

# ActiveX constants:
set(FBTYPELIB_NAME FlintPluginLib)
set(FBTYPELIB_DESC "FlintPlugin 1.0 Type Library")
set(IFBControl_DESC "FlintPlugin Control Interface")
set(FBControl_DESC "FlintPlugin Control Class")
set(IFBComJavascriptObject_DESC "FlintPlugin IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "FlintPlugin ComJavascriptObject Class")
set(IFBComEventSource_DESC "FlintPlugin IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID b358f6b4-3e56-5137-9963-df90f225bd06)
set(IFBControl_GUID 17a254ff-f30f-535a-ad05-75a11255b433)
set(FBControl_GUID 10d2523c-01e2-569b-a149-b08a813438ad)
set(IFBComJavascriptObject_GUID 390cae9c-12ad-511c-8353-37731932cc9c)
set(FBComJavascriptObject_GUID b6a81c1c-0133-5927-9649-4e063a0601fc)
set(IFBComEventSource_GUID c5ba9fc8-d2d5-5a56-b818-0e59a3c71f3b)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID b1557e5f-f9d5-5c2f-af2c-ea7c355dc8b7)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID b8607c8b-5f3f-5156-83fb-74edfbced036)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "OpenFlint.FlintPlugin")
if ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "openflint.org/FlintPlugin")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "openflint.org/FlintPlugin_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )

# strings
set(FBSTRING_CompanyName "OpenFlint")
set(FBSTRING_PluginDescription "OpenFlint Native Plugin")
set(FBSTRING_PLUGIN_VERSION "1.0.0.6")
set(FBSTRING_LegalCopyright "Copyright 2014 OpenFlint")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}")
set(FBSTRING_ProductName "FlintPlugin")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "FlintPlugin")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "FlintPlugin_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-flintplugin")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
