#include "helloworld.h"
#include "GridTest.hpp"
#include "exampleScaleable.hpp"
#include "labelExample.hpp"
#include <gtkmm/application.h>
#include <iostream>
#include <bibcpp/progutils.h>


using MapStrStr = std::map<std::string, std::string>;


class gtkmmExampleRunner : public bib::progutils::programRunner {
 public:
	gtkmmExampleRunner();
	static int exampleScaleable(MapStrStr inputCommands){
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
		::exampleScaleable example;
		return app->run(example);
	}
	static int randColorButtonGrid(MapStrStr inputCommands) {
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
		HelloWorld helloworld;
		return app->run(helloworld);
	}
	static int labelExample(MapStrStr inputCommands) {
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
		::labelExample lExample;
		return app->run(lExample);
	}
};

gtkmmExampleRunner::gtkmmExampleRunner()
    : bib::progutils::programRunner(
          {
					 addFunc("labelExample", labelExample, false),
					 addFunc("randColorButtonGrid", randColorButtonGrid, false),
					 addFunc("exampleScaleable", exampleScaleable, false)
           },
          "tester") {}

int main(int argc, char *argv[]) {

	gtkmmExampleRunner runner;
	return runner.run(argc,argv);
}
