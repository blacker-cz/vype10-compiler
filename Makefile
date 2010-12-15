# Makefile - VYPe "vype10" project 2010

# C++ compiler
CXX := g++

# Standard flags for C++ 
CXXFLAGS := -Wall

# Standard preprocessor flags (common for CC and CXX) 
CPPFLAGS :=

# Standard linker flags 
LDFLAGS :=

# Doxygen flags
DOXYFLAGS := 

### Variables: ###

VYPE_CXXFLAGS =  -I. $(CPPFLAGS) $(CXXFLAGS)
VYPE_OBJECTS =  \
  vype10.o compiler.o lex.yy.o parser.tab.o symbolTable.o intermediateCode.o
VYPE_SRCS = \
  vype10.cpp compiler.cpp lex.yy.cc parser.tab.cc symbolTable.cpp intermediateCode.cpp
VYPE_HEADERS = \
  misc.h compiler.h FlexLexer.h scanner.h stack.hh position.hh parser.tab.hh location.hh symbolTable.h intermediateCode.h
  

### Targets: ###

all: vype10

clean: 
	rm -f ./*.o
	rm -f ./*~
	rm -f ./*.log
	rm -f ./vype10
	rm -f -r ./doc/*

$(VYPE_OBJECTS): $(VYPE_SRCS)
	$(CXX) -c $(VYPE_CXXFLAGS) $(VYPE_SRCS)

vype10: $(VYPE_OBJECTS)
	$(CXX) -o $@ $(VYPE_OBJECTS) $(LDFLAGS)

doc: $(VYPE_SRCS) Doxyfile
	doxygen $(DOXYFLAGS)

# Packing
pack:
	make clean
	zip -r vype10.zip $(VYPE_SRCS) $(VYPE_HEADERS) Makefile -x *.svn* *.git*

.PHONY: all clean