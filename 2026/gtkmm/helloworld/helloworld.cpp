#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld()
: m_button("Hello World")   // creates a new button with label "Hello World".
,m_button2("and I am another")
			  // 
{
  // Sets the margin around the button.
  m_button2.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_button_clicked));
  // [this] { on_button_clicked();
  m_button2.signal_toggled().connect([this](){std::cout << "here" << std::endl;});

  // This packs the button into the Window (a container).
  set_child(m_button2);
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
  std::cout << "Hello World" << std::endl;
}
