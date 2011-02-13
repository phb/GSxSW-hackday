/**********************************************************\

  Auto-generated GazifyAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "GazifyAPI.h"

#include <spotify.h>

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyAPI::GazifyAPI(const GazifyPtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
GazifyAPI::GazifyAPI(const GazifyPtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host)
{
    registerMethod("playTrack",      make_method(this, &GazifyAPI::playTrack));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyAPI::~GazifyAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
GazifyAPI::~GazifyAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn GazifyPtr GazifyAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
GazifyPtr GazifyAPI::getPlugin()
{
    GazifyPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}


void GazifyAPI::playTrack(std::string var)
{
    printf("playing %s\n", var.c_str());
    spotify_play(var.c_str());
}

