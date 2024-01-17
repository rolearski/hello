#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld(const char* s)
: m_button(_(s))   // creates a new button with label
{
  this->set_title(_(s));
  // Sets the border width of the window.
  set_border_width(10);
  set_size_request(300, 100);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_button_clicked));

  // This packs the button into the Window (a container).
  add(m_button);

  // The final step is to display this newly created widget...
  m_button.show();
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
  std::string s = std::string( _("Let’s make the web multilingual.") );
  //std::string s = std::string( _("Not existing address") ) ;
  this->m_button.set_label(s);
  //s = std::string(_("Open existing addresses set"));
  this->m_button.set_label(s);
  this->m_button.set_label(_("Hi Barbara"));

  this->set_title(s);
  std::cout << s << std::endl;
}
