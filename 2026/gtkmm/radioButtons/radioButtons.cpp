#include "radioButtons.h"
#include <iostream>

RadioButtons::RadioButtons() :
  m_Box_Top(Gtk::Orientation::VERTICAL),
  m_Box1(Gtk::Orientation::VERTICAL, 10),
  m_Box2(Gtk::Orientation::VERTICAL, 10),
  m_RadioButton1("button1"),
  m_RadioButton2("button2"),
  m_RadioButton3("button3"),
  m_Button_Close("close")
{
  // Set title and border of the window
  set_title("radio buttons");

  // Gtk::CheckButton and Gtk::ToggleButton have set_group() methods.
  // They act as radio buttons, if they are included in a group.

  // Put radio buttons 2 and 3 in the same group as 1:
  m_RadioButton2.set_group(m_RadioButton1);
  m_RadioButton3.set_group(m_RadioButton1);

  // Add outer box to the window (because the window
  // can only contain a single widget)
  set_child(m_Box_Top);

  //Put the inner boxes and the separator in the outer box:
  m_Box_Top.append(m_Box1);
  m_Box_Top.append(m_Separator);
  m_Box_Top.append(m_Box2);
  m_Separator.set_expand();

  // Set the inner boxes' margins
  m_Box1.set_margin(10);
  m_Box2.set_margin(10);

  // Put the radio buttons in Box1:
  m_Box1.append(m_RadioButton1);
  m_Box1.append(m_RadioButton2);
  m_Box1.append(m_RadioButton3);
  m_RadioButton1.set_expand();
  m_RadioButton2.set_expand();
  m_RadioButton3.set_expand();

  // Set the second button active
  m_RadioButton2.set_active(true);

  // Put Close button in Box2:
  m_Box2.append(m_Button_Close);
  m_Button_Close.set_expand();

  // Make the button the default widget
  set_default_widget(m_Button_Close);

  // Connect the toggled signal of the button to
  // RadioButtons::on_button_toggled()
  m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this,
              &RadioButtons::on_button_clicked) );
  m_RadioButton1.signal_toggled().connect(sigc::mem_fun(*this,
                    &RadioButtons::on_r1) );
  m_RadioButton2.signal_toggled().connect(sigc::mem_fun(*this,
                    &RadioButtons::on_r2) );
  m_RadioButton3.signal_toggled().connect(sigc::mem_fun(*this,
                    &RadioButtons::on_r3) );
}

RadioButtons::~RadioButtons()
{
}

void RadioButtons::on_rX()
{
	//std::cout << "here" << std::endl;
	//std::cout << "this.get_active() " << this->get_active() << std::endl;
}

void RadioButtons::on_r1()
{
	std::cout << "button r1 " <<  m_RadioButton1.get_active() << std::endl;
}
void RadioButtons::on_r2()
{
	std::cout << "button r2 " <<  m_RadioButton2.get_active() << std::endl;
}
void RadioButtons::on_r3()
{
	std::cout << "button r3 " <<  m_RadioButton3.get_active() << std::endl;
}

void RadioButtons::on_button_clicked()
{
  close();
//	std::cout << "xxx" << std::endl;
}

