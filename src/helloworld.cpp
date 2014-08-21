#include "helloworld.h"
#include <iostream>
#include <random>
#include <gdkmm/rgba.h>


HelloWorld::HelloWorld()
   // creates a new button with label "Hello World".
{
  // Sets the border width of the window.
  set_border_width(10);
  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.

  mainGrid_.attach(gt1_, 1,1,1,1);
  mainGrid_.attach(gt2_, 1,2,1,1);
  mainGrid_.attach(gt3_, 1,3,1,1);
  mainGrid_.attach(gt4_, 1,4,1,1);
  // This packs the button into the Window (a container).
  //add(m_button);
  add(mainGrid_);

  // The final step is to display this newly created widget...
  mainGrid_.show_all();
}

HelloWorld::~HelloWorld(){

}

void HelloWorld::on_button_clicked(){
  std::mt19937_64 mtGen;
  std::random_device rd;
  mtGen.seed(rd());
  std::uniform_real_distribution<> disDoubMt(0, 1);
  Gdk::RGBA color;
  color.set_rgba(disDoubMt(mtGen),disDoubMt(mtGen),disDoubMt(mtGen));
 /* m_button.override_background_color(color);
  m_button.set_label(color.to_string());*/
}
