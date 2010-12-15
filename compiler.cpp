/*
 * VYPe 2010 Compiler project
 *//**
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

	this->trace_scanning = false;
	this->trace_parsing = 0;

	this->errorLevel = RET_ERR_OK;

	this->symbolTable = new SymbolTable();
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

	this->trace_scanning = false;
	this->trace_parsing = 0;

	this->errorLevel = RET_ERR_OK;

	this->symbolTable = new SymbolTable();
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
    scanner.parent = this;
    scanner.set_debug(this->trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(this->trace_parsing);
    parser.parse();

    if(this->errorLevel != RET_ERR_OK)
    	return this->errorLevel;

    // check if all declared functions are also defined
    std::string *name = symbolTable->getUndefinedFunctions();
    if(name != (std::string*) NULL) {
    	error("Declared but undefined function '" + *name +"'", RET_ERR_SEMANTICAL);
        return this->errorLevel;
    }

    // check if main function is defined
    name = new string("main");
    if(symbolTable->getFunction(name) == (SymbolTable::FunctionRecord*) NULL) {
    	error("Undefined function '" + *name +"'", RET_ERR_SEMANTICAL);
    	delete name;
        return this->errorLevel;
    }
    delete name;

    return this->errorLevel;
}

/**
 * Error handling with associated line number.
 *
 * @param &location		location
 * @param &string		message
 * @param int			errorType
 */
void Compiler::error(const class location& l, const std::string& m, int errorType) {
	string err;

	this->errorLevel = errorType;

	switch(errorType) {
	case RET_ERR_LEXICAL: err = "Lexical error:";
		break;
	case RET_ERR_SYNTACTICAL: err = "Syntactical error:";
		break;
	case RET_ERR_SEMANTICAL: err = "Semantical error:";
		break;
	case RET_ERR_GENERATION: err = "Generation error:";
		break;
	case RET_ERR_INTERNAL: err = "Internal error:";
		break;
	default:
		this->errorLevel = RET_ERR_INTERNAL;
		break;
	}

	cerr << err << l << ": " << m << endl;
}

/**
 * General error handling.
 *
 * @param &string		message
 * @param int			errorType
 */
void Compiler::error(const std::string& m, int errorType) {
	string err;

	this->errorLevel = errorType;

	switch(errorType) {
	case RET_ERR_LEXICAL: err = "Lexical error:";
		break;
	case RET_ERR_SYNTACTICAL: err = "Syntactical error:";
		break;
	case RET_ERR_SEMANTICAL: err = "Semantical error:";
		break;
	case RET_ERR_GENERATION: err = "Generation error:";
		break;
	case RET_ERR_INTERNAL: err = "Internal error:";
		break;
	default:
		this->errorLevel = RET_ERR_INTERNAL;
		break;
	}

	cerr << err << " " << m << endl;
}

/**
 * Cleanup method invoked by lexical analyzer in case of lexical error.
 */
void Compiler::cleanup(void) {
	/**  @todo: do cleanup here */
}

}
