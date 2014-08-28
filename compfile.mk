CC = /usr/bin/clang
CXX = /usr/bin/clang++
CXXOUTNAME = gtkmmExperiment
CXXFLAGS = -std=c++11 -Wall
CXXOPT += -O2 -funroll-loops -DNDEBUG  
ifneq ($(shell uname -s),Darwin)
	CXXOPT += -march=native -mtune=native
endif

#debug
CXXDEBUG = -g -gstabs+ 
INSTALL_DIR=INSTALL_LOCATION

#USE_CPPITERTOOLS = 1
#USE_CPPPROGUTILS = 1
#USE_ZI_LIB = 1
#USE_BOOST = 1
#USE_R = 1
#USE_BAMTOOLS = 1
#USE_CPPCMS = 1
#USE_MATHGL = 1
#USE_ARMADILLO = 1
#USE_MLPACK = 1
#USE_liblinear = 1
#USE_PEAR = 1
#USE_CURL = 1
#USE_LIBGDAMM = 1
USE_GTKMM = 1
