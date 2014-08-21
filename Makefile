ROOT = $(realpath ./)
EXT_PATH=$(realpath external)
LIB_DIR=$(ROOT)/lib

COMPFILE=$(ROOT)/compfile.mk

include $(COMPFILE)
include $(ROOT)/makefile-common.mk


ifndef COMPFILE
	$(error $(COMPFILE) is not set)
endif

UNAME_S := $(shell uname -s)
# from http://stackoverflow.com/a/8654800
HEADERS = $(call rwildcard, src/, *.h) \
	$(call rwildcard, src/, *.hpp)

OBJ_DIR = $(addprefix build/, $(addsuffix Build, $(CXXOUTNAME)))
OBJ = $(addprefix $(OBJ_DIR)/, $(patsubst %.cpp, %.o, $(call rwildcard, src/, *.cpp))) 
OBJNOMAIN = $(filter-out $(addsuffix /src/main.o, $(OBJ_DIR)), $(OBJ))



BIN = $(addsuffix $(CXXOUTNAME), bin/)
DYLIB = $(addprefix $(addsuffix $(CXXOUTNAME), $(LIB_DIR)/lib), .dylib)
SOLIB = $(addprefix $(addsuffix $(CXXOUTNAME), $(LIB_DIR)/lib), .so)
COMMON = $(CXXFLAGS) $(CXXOPT) $(COMLIBS) `pkg-config gtkmm-3.0 --cflags`




-include do_preReqs
############ main
.PHONY: all
all: do_preReqs $(OBJ_DIR) $(BIN) 
	scripts/fixDyLinking_mac.sh bin external
	

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p bin
	mkdir -p lib

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(shell dirname $<)
	$(CXX) -DNOT_HEADER_ONLY $(COMMON)  -fpic -c $< -o $@

$(BIN): $(OBJ) $(OBJ_DIR)/src/main.o
	$(CXX) $(COMMON) -o $@ $^ $(LD_FLAGS) `pkg-config gtkmm-3.0 --libs`
	

	
############ remove the objects that were dependant the changed headers 
.PHONY: do_script
do_script:
	scripts/rmNeedToRecompile.py -obj $(OBJ_DIR) -src src/

prerequisites: do_script

.PHONY: do_preReqs 
do_preReqs: prerequisites

	
############ shared library
.PHONY: sharedLibrary
sharedLibrary: $(OBJ_DIR) $(SOLIB)
	scripts/fixDyLinking_mac.sh lib external

$(SOLIB): $(OBJNOMAIN)
	$(CXX) $(COMMON) -shared -o $@ $^ $(LD_FLAGS) 
	
############ dylibLibrary
.PHONY: dylibLibrary
dylibLibrary: $(OBJ_DIR) $(DYLIB)
	scripts/fixDyLinking_mac.sh lib external
$(DYLIB): $(OBJNOMAIN)
	$(CXX) $(COMMON) -dynamiclib -o $@ $^ $(LD_FLAGS) 


############ clean
.PHONY: clean
clean:
	@rm -f $(BIN)
	@rm -rf $(OBJ_DIR)
	
	
############ install
.PHONY: install
install: $(INSTALL_DIR) moveHeaders $(OBJ_DIR) $(INSTALL_DIR)/lib/$(CXXOUTNAME).so $(INSTALL_DIR)/lib/$(CXXOUTNAME).dylib $(INSTALL_DIR)/bin/$(CXXOUTNAME) 
	scripts/fixDyLinking_mac.sh $(INSTALL_DIR)/lib/ external
	scripts/fixDyLinking_mac.sh $(INSTALL_DIR)/bin/ external
	
$(INSTALL_DIR):
	@mkdir -p $(INSTALL_DIR)/include
	@mkdir -p $(INSTALL_DIR)/bin
	@mkdir -p $(INSTALL_DIR)/lib
	
$(INSTALL_DIR)/lib/$(CXXOUTNAME).so: $(OBJNOMAIN)
	$(CXX) $(COMMON) -shared -o $(realpath $(INSTALL_DIR))/lib/$(CXXOUTNAME).so $^ $(LD_FLAGS) 

$(INSTALL_DIR)/lib/$(CXXOUTNAME).dylib: $(OBJNOMAIN)
	$(CXX) $(COMMON) -dynamiclib -o $(realpath $(INSTALL_DIR))/lib/$(CXXOUTNAME).dylib $^ $(LD_FLAGS)  

$(INSTALL_DIR)/bin/$(CXXOUTNAME):$(OBJ) $(OBJ_DIR)/src/main.o
	$(CXX) $(COMMON) -o $(realpath $(INSTALL_DIR))/bin/$(CXXOUTNAME) $^ $(LD_FLAGS) 


.PHONY moveHeaders:
moveHeaders: $(INSTALL_DIR)
	scripts/reDirMove.sh src/ $(INSTALL_DIR)/include/
	
	

	