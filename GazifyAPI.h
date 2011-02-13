/**********************************************************\

  Auto-generated GazifyAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "Gazify.h"

#ifndef H_GazifyAPI
#define H_GazifyAPI

class GazifyAPI : public FB::JSAPIAuto
{
public:
    GazifyAPI(const GazifyPtr& plugin, const FB::BrowserHostPtr& host);
    virtual ~GazifyAPI();

    GazifyPtr getPlugin();

    void playTrack(std::string uri);
    

private:
    GazifyWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_GazifyAPI

