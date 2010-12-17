/*
 * VYPe 2010 Compiler project
 *//**
 * Assembler code generation class.
 */

#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include <string>
#include "symbolTable.h"
#include "intermediateCode.h"
#include "compiler.h"
#include "misc.h"

namespace vype10 {

class CodeGenerator {
public:
	CodeGenerator(IntermediateCode *intermediateCode, std::string output);
	virtual ~CodeGenerator();

	/** Compiler class */
	class Compiler *compiler;

	void run(void);

private:
	/** Class with intermediate code */
	IntermediateCode *intermediateCode;

	/** Path to the output file */
	std::string output;

};

}

#endif /* CODEGENERATOR_H_ */
