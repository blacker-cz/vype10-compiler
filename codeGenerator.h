/*
 * VYPe 2010 Compiler project
 *//**
 * Assembler code generation class.
 */

#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include "symbolTable.h"
#include "intermediateCode.h"
#include "misc.h"

namespace vype10 {

class CodeGenerator {
public:
	CodeGenerator(IntermediateCode *intermediateCode);
	virtual ~CodeGenerator();

	/** Compiler class */
	class Compiler *compiler;

	void run(void);

private:
	IntermediateCode *intermediateCode;
};

}

#endif /* CODEGENERATOR_H_ */
