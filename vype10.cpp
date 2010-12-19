/*
 * VYPe 2010 Compiler project
 *//**
 * Main application file.
 * @author: Lukáš Černý <xcerny37@stud.fit.vutbr.cz>
 */

#include <iostream>
#include <string>
#include "compiler.h"

using namespace std;
using namespace vype10;

/**
 * Program main function
 * @param int 		argument count
 * @param char**	argument strings
 */
int main(int argc, char** argv) {

	if(argc == 1 || argc > 3) {
		cerr << "Invalid arguments passed." << endl;
		return RET_ERR_INTERNAL;
	}

	Compiler *compiler = NULL;
	int retval;

	if(argc == 2)
		compiler = new Compiler(argv[1]);
	else
		compiler = new Compiler(argv[1], argv[2]);

	retval = compiler->run();

	delete compiler;

	return retval;
}
