#PKG_CONFIG_PATH=/u/cs_build/gtkmm/lib/pkgconfig/
#LD_LIBRARY_PATH=/u/cs_build/gtkmm/lib
CXX= g++ -std=c++14
CXXFLAGS = -Wall `pkg-config gtkmm-3.0 --cflags` -MMD
LDFLAGS=`pkg-config gtkmm-3.0 --libs`
SOURCES = $(wildcard *.cc) # list of all .cc files in the current directory
OBJECTS = ${SOURCES:.cc=.o} # .o files depend upon .cc files with same names
DEPENDS = ${OBJECTS:.o=.d}  # .d file is list of dependencies for corresponding .cc file
EXEC_GUI = mvc_gui
EXEC_TEXT = mvc_text

ALL: $(EXEC_GUI) $(EXEC_TEXT)

$(EXEC_GUI): $(filter-out main_text.o, $(OBJECTS))
	$(CXX) $(filter-out main_text.o, $(OBJECTS)) -o $(EXEC_GUI) $(CXXFLAGS) $(LDFLAGS)

$(EXEC_TEXT): $(filter-out main.o, $(OBJECTS))
	$(CXX) $(filter-out main.o, $(OBJECTS)) -o $(EXEC_TEXT) $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean ALL

clean:
	rm $(EXEC_GUI) $(EXEC_TEXT) $(OBJECTS) $(DEPENDS)

-include ${DEPENDS} # reads the .d files and reruns dependencies
