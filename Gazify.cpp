/**********************************************************\

  Auto-generated Gazify.cpp

  This file contains the auto-generated main plugin object
  implementation for the Gazify project

\**********************************************************/

#include "GazifyAPI.h"
#include "DOM.h"
#include "variant_list.h"
#include "coordinate_server.h"
#include "Gazify.h"
#include "spotify.h"
#include "audio.h"
#include "coordinate_server.h"

using namespace FB;

///////////////////////////////////////////////////////////////////////////////
/// @fn Gazify::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void Gazify::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process
    spotify_init(SPOTIFY_USER,SPOTIFY_PASSWORD);
}

///////////////////////////////////////////////////////////////////////////////
/// @fn Gazify::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void Gazify::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded
    spotify_exit();
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Gazify constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
Gazify::Gazify()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Gazify destructor.
///////////////////////////////////////////////////////////////////////////////
Gazify::~Gazify()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void Gazify::gaze(int x,int y)
{
    if(!m_host->isMainThread()) {
        m_host->CallOnMainThread(boost::bind(&Gazify::gaze, this, x, y));
    }
    printf("Got coordinate %d,%d on main thread\n",x,y);
}

void Gazify::onPluginReady()
{
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
#ifdef USE_REMOTE
    pthread_t p;
    pthread_create(&p,NULL,&coordiate_thread,this);
#endif
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<Gazify> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr Gazify::createJSAPI()
{
    // m_host is the BrowserHost
    return boost::make_shared<GazifyAPI>(FB::ptr_cast<Gazify>(shared_from_this()), m_host);
}

bool Gazify::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *)
{
    std::string s = trackAtScreenCoordinates(evt->m_x*2, 100+evt->m_y*2);
    if(!s.empty()) {
        spotify_play(s.c_str());
    }
    printf("Heyo: %s\n", s.c_str());
    return false;
}

bool Gazify::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *)
{
    return false;
}

bool Gazify::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *)
{
    return false;
}
bool Gazify::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *)
{
    // The window is attached; act appropriately
    return false;
}

bool Gazify::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    // The window is about to be detached; act appropriately
    return false;
}

std::string Gazify::trackAtScreenCoordinates(float x, float y)
{
    Rect wndRect = GetWindow()->getWindowPosition();
    /*x -= wndRect.left;
    y -= wndRect.top;*/ // add back when we get real coordinates
    DOM::DocumentPtr doc = m_host->getDOMDocument();
    JSObjectPtr elementUnderGazeJs = doc->callMethod<JSObjectPtr>("elementFromPoint", variant_list_of(x)(y));
    
    std::string ret = "<nothing>";
    int depth = 0;
    while (elementUnderGazeJs && depth < 100) { // walking up the tree looking for gazemusic attr
        DOM::ElementPtr elementUnderGaze = DOM::Element::create(elementUnderGazeJs);
        if(elementUnderGaze->callMethod<bool>("hasAttribute", variant_list_of("gazemusic"))) {
            try {
                ret = elementUnderGaze->getStringAttribute("gazemusic");
                if(!ret.empty()) break;
            } catch (bad_variant_cast bvc) {}
        }
        
        elementUnderGaze = elementUnderGaze->getParentNode();
        depth++;
    }
    return ret;
}

