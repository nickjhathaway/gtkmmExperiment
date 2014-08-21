#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include "GridTest.hpp"

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  virtual ~HelloWorld();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Grid mainGrid_;
  GridTest gt1_;
  GridTest gt2_;
  GridTest gt3_;
  GridTest gt4_;

};
