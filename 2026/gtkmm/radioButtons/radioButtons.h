#ifndef GTKMM_EXAMPLE_RADIOBUTTONS_H
#define GTKMM_EXAMPLE_RADIOBUTTONS_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/separator.h>

class RadioButtons : public Gtk::Window
{
public:
  RadioButtons();
  virtual ~RadioButtons();

protected:
  //Signal handlers:
  void on_button_clicked();
  void on_r1();
  void on_r2();
  void on_r3();
  void on_rX();

  //Child widgets:
  Gtk::Box m_Box_Top, m_Box1, m_Box2;
  Gtk::CheckButton m_RadioButton1, m_RadioButton2, m_RadioButton3;
  Gtk::Separator m_Separator;
  Gtk::Button m_Button_Close;
};

#endif //GTKMM_EXAMPLE_RADIOBUTTONS_H
