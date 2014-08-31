CC = /usr/bin/clang
CXX = /usr/bin/clang++
CXXOUTNAME = gtkmmTest
CXXFLAGS = -std=c++11 -Wall
CXXOPT += -O2 -funroll-loops -DNDEBUG  
ifneq ($(shell uname -s),Darwin)
	CXXOPT += -march=native -mtune=native
endif

#debug
CXXDEBUG = -g -gstabs+ 
INSTALL_DIR=./gtkmmExperiment
EXT_PATH=$(realpath ../external)
SCRIPTS_DIR=$(realpath scripts)

USE_CPPITERTOOLS = 0
USE_CPPPROGUTILS = 0
USE_ZI_LIB = 0
USE_BOOST = 0
USE_R = 0
USE_BAMTOOLS = 0
USE_CPPCMS = 0
USE_MATHGL = 0
USE_ARMADILLO = 0
USE_MLPACK = 0
USE_LIBLINEAR = 0
USE_PEAR = 0
USE_CURL = 0
USE_GTKMM = 1
USE_BIBCPP = 0
