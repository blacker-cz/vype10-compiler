/*
 * VYPe 2010 Compiler project
 *//**
 * Assembler code generation class.
 */

#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include <string>
#include <fstream>
#include <algorithm>
#include "symbolTable.h"
#include "intermediateCode.h"
#include "compiler.h"
#include "misc.h"

#define comment(x)		output << "// " << x << std::endl
#define command(x)		output << "\t" << x << std::endl
#define label(x)		output << x << std::endl

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

	/** Stream for output file */
	std::ofstream output;

	void head(void);

	void data(void);

	std::string generateName(std::string);

	bool process(IntermediateCode::InstructionRecord* instruction);

};

}

#endif /* CODEGENERATOR_H_ */
