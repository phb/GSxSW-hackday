#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Gazify
#
#\**********************************************************/

set(PLUGIN_NAME "Gazify")
set(PLUGIN_PREFIX "GAZ")
set(COMPANY_NAME "Spotify")

# ActiveX constants:
set(FBTYPELIB_NAME GazifyLib)
set(FBTYPELIB_DESC "Gazify 1.0 Type Library")
set(IFBControl_DESC "Gazify Control Interface")
set(FBControl_DESC "Gazify Control Class")
set(IFBComJavascriptObject_DESC "Gazify IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "Gazify ComJavascriptObject Class")
set(IFBComEventSource_DESC "Gazify IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 93237fa5-0b0b-5b8d-a45a-a1aff2d5b8e5)
set(IFBControl_GUID 35e578d3-8722-5671-9eb7-f12433b4f8c8)
set(FBControl_GUID 201073e3-d82e-5fa1-9f9c-af4e39a3de50)
set(IFBComJavascriptObject_GUID d0def45c-25d4-5b9a-bb56-068d153accff)
set(FBComJavascriptObject_GUID 09d4e549-8af4-5d6d-8932-5913f54f3778)
set(IFBComEventSource_GUID f6265907-93e7-5d2f-a8cb-7a6fac7183e2)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "Spotify.Gazify")
set(MOZILLA_PLUGINID "spotify.com/Gazify")

# strings
set(FBSTRING_CompanyName "Spotify")
set(FBSTRING_FileDescription "Spotify+gaze tracking")
set(FBSTRING_PLUGIN_VERSION "1.0.0")
set(FBSTRING_LegalCopyright "Copyright 2011 Spotify")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Gazify")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Gazify")
set(FBSTRING_MIMEType "application/x-gazify")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

# set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
