#include "helloworld.h"
#include <gtkmm/application.h>

// g++ main.cpp helloworld.cpp `pkg-config gtkmm-4.0 --cflags --libs gtkmm-4.0`

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<HelloWorld>(argc, argv);
}
