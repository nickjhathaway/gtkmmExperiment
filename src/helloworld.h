#pragma once
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/image.h>
#include "GridTest.hpp"
#include <gtkmm/colorbutton.h>
#include <gtkmm/checkbutton.h>

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
  Gtk::Grid entryGrid_;
  Gtk::Entry et1_;
  Gtk::SpinButton spt1_;
  Gtk::Entry et2_;
  Gtk::SpinButton spt2_;
  Gtk::Image gImagTest_;
  Gtk::CheckButton cbTest_;

};
