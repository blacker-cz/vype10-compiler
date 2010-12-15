/*
 * VYPe 2010 Compiler project
 *//**
 * Header file containing definition of Compiler class.
 */

#ifndef VYPE10_COMPILER_H_
#define VYPE10_COMPILER_H_

#include <string>
#include "symbolTable.h"
#include "intermediateCode.h"
#include "location.hh"
#include "misc.h"

namespace vype10 {

	class Compiler {
		private:
			std::string input;
			std::string output;

			/** Error level */
			int errorLevel;

		public:
			Compiler(std::string input);
			Compiler(std::string input, std::string output);

			int run(void);

			class Scanner* lexer;

			class SymbolTable* symbolTable;

			class IntermediateCode* intermediateCode;

			/** Stream name used for error messages */
			std::string streamname;

		    /** enable debug output in the flex scanner */
		    bool trace_scanning;

		    /** enable debug output in the bison parser */
		    int trace_parsing;

		    void cleanup(void);

		    void error(const class location& l, const std::string& m, int errorType);

		    void error(const std::string& m, int errorType);

	};

}

#endif /* VYPE10_COMPILER_H_ */
