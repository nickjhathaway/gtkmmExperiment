#pragma once

/*

 * GridTest.hpp
 *
 *  Created on: Aug 21, 2014
 *      Author: nickhathaway
 */


#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include "RandColorButton.hpp"

class GridTest : public Gtk::Grid{
public:
	GridTest();

	RandColorButton b1;
	RandColorButton b2;
	RandColorButton b3;
	RandColorButton b4;


};


