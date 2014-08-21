#include "helloworld.h"
#include <iostream>
#include <random>
#include <gdkmm/rgba.h>
#include <libgdamm.h>
#include <libgnomedbmm.h>

HelloWorld::HelloWorld()
: m_button("Hello World")   // creates a new button with label "Hello World".
{
  // Sets the border width of the window.
  set_border_width(100);
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
  std::mt19937_64 mtGen;
  std::random_device rd;
  mtGen.seed(rd());
  std::uniform_real_distribution<> disDoubMt(0, 1);
  Gdk::RGBA color;
  color.set_rgba(disDoubMt(mtGen),disDoubMt(mtGen),disDoubMt(mtGen));
  m_button.override_background_color(color);
  m_button.set_label(color.to_string());
}
