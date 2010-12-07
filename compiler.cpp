/*
 * VYPe 2010 Compiler project
 *//***************************************************************************
 * Compiler a.k.a. main application class.
 */
#include <iostream>
#include <fstream>
#include "scanner.h"
#include "parser.tab.hh"
#include "compiler.h"
#include "misc.h"

using namespace std;

namespace vype10 {
/**
 * Constructor definition (overloaded)
 *
 * @param string	path to input file
 */
Compiler::Compiler(string input) {
	this->input = input;
	this->output = "out.asm";
}

/**
 * Constructor definition (overloaded)
 *
 * @param string	path to input file
 * @param string	path to output file
 */
Compiler::Compiler(string input, string output) {
	this->input = input;
	this->output = output;
}

/**
 * Starts compilation process.
 *
 * @return one of the RET_ERR_* codes
 */
int Compiler::run(void) {
	/** TODO: implement this :) */
    std::ifstream in(input.c_str());

    if (!in.good()) {
    	cerr << "Couldn't open input file." << endl;
    	return RET_ERR_INTERNAL;
    }

    streamname = input;

    Scanner scanner(&in);
    scanner.set_debug(false);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(true);
    return (parser.parse() == 0);

    return RET_ERR_OK;
}

/**
 * Error handling with associated line number.
 *
 * @param &location		location
 * @param &string		message
 */
void Compiler::error(const class location& l, const std::string& m) {
	cerr << l << ": " << m << endl;
}

/**
 * General error handling.
 *
 * @param &string		message
 */
void Compiler::error(const std::string& m) {
	cerr << m << endl;
}

}
