#include "helloworld.h"
#include "GridTest.hpp"
#include "exampleScaleable.hpp"
#include "labelExample.hpp"
#include <gtkmm/application.h>
#include <iostream>
int main (int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  //HelloWorld helloworld;
  //GridTest gTest;
  exampleScaleable example;
  //labelExample lExample;
  //Shows the window and returns when it is closed.
  //return app->run(lExample);
  return app->run(example);
  //return  app->run(helloworld);
  //return app->run(gTest);
}
