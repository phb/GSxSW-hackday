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

#define USE_REMOTE 1
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
    printf("gaze %d %d\n", x, y);
    if(!m_host->isMainThread()) {
        try {
            m_host->CallOnMainThread(boost::bind(&Gazify::gaze, this, x, y));
        } catch (...) {

        }
        return;
    }

    DOM::DocumentPtr doc = m_host->getDOMDocument();
    doc->callMethod<void>("gaze", variant_list_of(x)(y));
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
    /*
    std::string ret = "";
    DOM::WindowPtr win = m_host->getDOMWindow();
    
    int win_x = win->getProperty<int>("screenX");
    int win_y = win->getProperty<int>("screenY");
    int win_w = win->getProperty<int>("innerWidth");
    int win_h = win->getProperty<int>("innerHeight");
    fprintf(stderr,"inp: %d,%d and %d,%d,%d,%d\n",(int)x,(int)y,win_x,win_y,win_w,win_h);
    x -= win_x;
    y -= win_y;
    if(x < 0 || y < 0 || x > win_w || y > win_h)
    {
        printf("Coordinate outside window\n");
    }
    x += win->getProperty<int>("pageXOffset");
    y += win->getProperty<int>("pageYOffset");
    printf("PageXOffset: %d, YOff: %d\n",win->getProperty<int>("pageXOffset"),win->getProperty<int>("pageYOffset"));
    
    printf("Window coordinates: %d,%d\n",(int)x,(int)y);
    JSObjectPtr elementUnderGazeJs = doc->callMethod<JSObjectPtr>("elementFromPoint", variant_list_of(x)(y));
//DEBUG
    
    
    FB::DOM::ElementPtr blobb = doc->getElementById("red_blobb");
    printf("style: %s\n",blobb->getStringAttribute("class").c_str());
    blobb->setProperty("real_left","100px");
    blobb->setProperty("real_top","100px");


 //    printf("%d\n",blobb->getWidth());
//    blobb->setInnerHTML("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
//    printf("TYPE: %s\n",blobb->getProperty("nodeType").c_str());
//    blobb->setProperty("top",y);
    
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
     */
}

