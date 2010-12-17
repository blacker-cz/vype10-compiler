/*
 * VYPe 2010 Compiler project
 *//**
 * Assembler code generation class.
 */

#include "codeGenerator.h"

namespace vype10 {

/**
 * Constructor.
 *
 * @param IntermediateCode*		pointer to the intermediate code class
 */
CodeGenerator::CodeGenerator(IntermediateCode *intermediateCode) {
	this->intermediateCode = intermediateCode;
}

CodeGenerator::~CodeGenerator() {
	// TODO Auto-generated destructor stub
}

/**
 * Method which starts assembler generation.
 *
 * @return
 */
void CodeGenerator::run(void) {
	/**
	 * @todo: implement this
	 */
}

}
