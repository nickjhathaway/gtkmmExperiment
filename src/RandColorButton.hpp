#pragma once

/*

 * RandColorButton.hpp
 *
 *  Created on: Aug 21, 2014
 *      Author: nickhathaway
 */
#include <gtkmm/button.h>
#include <random>
#include <gdkmm/rgba.h>

class RandColorButton : public Gtk::Button {
public:

	RandColorButton(const std::string & lab);

  std::mt19937_64 mtGen_;

  std::uniform_real_distribution<> dis;

	void whenClicked();

};


