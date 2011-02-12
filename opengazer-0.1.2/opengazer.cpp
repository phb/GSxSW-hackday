#include <gtkmm.h>
#include <iostream>
#include "OutputMethods.h"
#if USE_GTK
#include "GazeTrackerGtk.h"
#include "GtkStore.h"
#endif

int main(int argc, char **argv)
{
#if USE_GTK
    Gtk::Main kit(argc, argv);
    Glib::thread_init();

//     CalibrationWindow calwindow;
//     calwindow.show();

    GazeTrackerGtk helloworld(argc, argv);

    helloworld.show();

    Gtk::Main::run(helloworld);
#else 
#warning implement me!!
#endif
    
    return 0;
}
