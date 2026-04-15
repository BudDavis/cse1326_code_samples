#pragma once

#include <gtkmm/window.h>
#include <gtkmm/dropdown.h>
#include <gtkmm/stringlist.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  ~ExampleWindow() override;

protected:
  // Signal handler:
  void on_dropdown_changed();

  // Child widget:
  Gtk::DropDown m_DropDown;

  Glib::RefPtr<Gtk::StringList> m_StringList;
};

