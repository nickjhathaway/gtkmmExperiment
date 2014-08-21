/*
 * RandColorButton.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: nickhathaway
 */

#include "RandColorButton.hpp"

RandColorButton::RandColorButton(const std::string & lab): Gtk::Button(lab){
  std::random_device rd;
  mtGen_.seed(rd());
  dis = std::uniform_real_distribution<> (0, 1);
  signal_clicked().connect(sigc::mem_fun(*this,
             &RandColorButton::whenClicked));
}

void RandColorButton::whenClicked(){
  Gdk::RGBA color;
  color.set_rgba(dis(mtGen_),dis(mtGen_),dis(mtGen_));
  override_background_color(color);
  set_label(color.to_string());
}
