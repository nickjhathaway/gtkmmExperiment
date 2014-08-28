#include "helloworld.h"
#include <iostream>
#include <random>
#include <gdkmm/rgba.h>


HelloWorld::HelloWorld()
   // creates a new button with label "Hello World".
{
  // Sets the border width of the window.
  set_border_width(10);
  set_title("Examples");
  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  entryGrid_.attach(et1_,1,1,1,1);
  entryGrid_.attach(et2_,2,1,1,1);
  mainGrid_.attach(gt1_, 1,1,1,1);
  mainGrid_.attach(gt2_, 1,2,1,1);
  mainGrid_.attach(gt3_, 1,3,1,1);
  mainGrid_.attach(gt4_, 1,4,1,1);
  spt1_.activate();
  spt1_.set_max_length(10);
  mainGrid_.attach(entryGrid_, 1,5,1,1);
  mainGrid_.attach(spt1_, 1,6,1,1);
  mainGrid_.attach(gImagTest_,1,7,1,1 );
  cbTest_.set_active(true);
  cbTest_.signal_clicked().connect(sigc::mem_fun(*this,
      &HelloWorld::on_button_clicked) );
  mainGrid_.attach(cbTest_, 1,8,1,1);
  cbTest_.set_label("Check_test");

  // This packs the button into the Window (a container).
  //add(m_button);
  add(mainGrid_);
  // The final step is to display this newly created widget...
  mainGrid_.show_all();

}

HelloWorld::~HelloWorld(){
  std::cout << "The Button was clicked: state="
        << (cbTest_.get_active() ? "true" : "false")
        << std::endl;
}

void HelloWorld::on_button_clicked(){
  std::mt19937_64 mtGen;
  std::random_device rd;
  mtGen.seed(rd());
  std::uniform_real_distribution<> disDoubMt(0, 1);
  Gdk::RGBA color;
  color.set_rgba(disDoubMt(mtGen),disDoubMt(mtGen),disDoubMt(mtGen));
  std::cout << "The Button was clicked: state="
        << (cbTest_.get_active() ? "true" : "false")
        << std::endl;
  cbTest_.override_background_color(color);
 /* m_button.override_background_color(color);
  m_button.set_label(color.to_string());*/
}
