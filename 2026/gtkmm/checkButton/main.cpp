#include "examplewindow.h"
#include <gtkmm/application.h>
#include <iostream>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  std::cout << "the var is " << typeid(app).name() ;
  std::cout << std::endl;
  //Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}
