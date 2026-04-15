#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow()
{
  set_title("DropDown example");

  set_child(m_DropDown);

  // Fill the dropdown:
  const std::vector<Glib::ustring> strings{
    "1 minute", "2 minutes", "5 minutes", "20 minutes"
  };
  m_StringList = Gtk::StringList::create(strings);
  m_DropDown.set_model(m_StringList);
  m_DropDown.set_selected(0);

  // Connect signal handler:
  m_DropDown.property_selected().signal_changed().connect(
    sigc::mem_fun(*this, &ExampleWindow::on_dropdown_changed));
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_dropdown_changed()
{
  const auto selected = m_DropDown.get_selected();
  std::cout << "DropDown changed: Row=" << selected
    << ", String=" << m_StringList->get_string(selected) << std::endl;
}
