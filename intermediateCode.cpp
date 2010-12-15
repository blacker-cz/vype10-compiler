/*
 * VYPe 2010 Compiler project
 *//**
 * Intermediate code class.
 */

#include "intermediateCode.h"

namespace vype10 {

IntermediateCode::IntermediateCode() {
	// TODO Auto-generated constructor stub

}

IntermediateCode::~IntermediateCode() {
	// TODO Auto-generated destructor stub
}

/**
 * Method for adding instruction.
 *
 * @param Instruction		type of instruction
 * @param std::string*		pointer with key to the symbol table for first param
 * @param std::string*		pointer with key to the symbol table for second param
 * @param std::string*		pointer with key to the symbol table where to store result
 */
void IntermediateCode::add(Instruction instruction, std::string* firstParam, std::string* secondParam, std::string* result) {
	/**
	 * @todo: implement this :)
	 */
}

}
