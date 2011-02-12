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

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);
    
    // Method test-event
    void testEvent(const FB::variant& s);

private:
    GazifyWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_GazifyAPI

