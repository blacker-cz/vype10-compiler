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
  vype10.o compiler.o lex.yy.o parser.tab.o symbolTable.o intermediateCode.o codeGenerator.o
VYPE_SRCS = \
  vype10.cpp compiler.cpp lex.yy.cc parser.tab.cc symbolTable.cpp intermediateCode.cpp codeGenerator.cpp
VYPE_HEADERS = \
  misc.h compiler.h FlexLexer.h scanner.h stack.hh position.hh parser.tab.hh location.hh symbolTable.h intermediateCode.h codeGenerator.h
  

### Targets: ###

all: vype

clean: 
	rm -f ./*.o
	rm -f ./*~
	rm -f ./*.log
	rm -f ./vype
	rm -f -r ./doc/*

$(VYPE_OBJECTS): $(VYPE_SRCS)
	$(CXX) -c $(VYPE_CXXFLAGS) $(VYPE_SRCS)

vype: $(VYPE_OBJECTS)
	$(CXX) -o $@ $(VYPE_OBJECTS) $(LDFLAGS)

doc: $(VYPE_SRCS) Doxyfile
	doxygen $(DOXYFLAGS)

# Packing
pack:
	make clean
	zip -r xcerny37.zip $(VYPE_SRCS) $(VYPE_HEADERS) Makefile rozdeleni -x *.svn* *.git*

.PHONY: all clean
