/*
 * VYPe 2010 Compiler project
 *//**
 * Intermediate code class.
 */

#include <iostream>
#include "intermediateCode.h"

namespace vype10 {

/**
 * Constructor
 */
IntermediateCode::IntermediateCode() {
	// initialization of instruction line iterator
	instructionLineIter = instructionLine.begin();
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
	// build instruction record
	InstructionRecord* ins = new InstructionRecord();
	ins->instruction = instruction;
	ins->first = firstParam;
	ins->second = secondParam;
	ins->result = result;

	// push instruction record to the end of instruction line
	instructionLine.push_back(ins);

	// debug output
	std::cerr << "Instruction: " << instruction << ", " << (firstParam==(std::string*)NULL ? "NULL" : *firstParam)
			<< ", " << (secondParam==(std::string*)NULL ? "NULL" : *secondParam)
			<< ", "	<< (result==(std::string*)NULL ? "NULL" : *result) << std::endl;
}

/**
 * Gets actual instruction record and moves private iterator to the next one.
 *
 * @return InstructionRecord*		pointer to the instruction record or NULL if no instruction is available
 */
IntermediateCode::InstructionRecord *IntermediateCode::get(void) {
	if(instructionLineIter == instructionLine.end())
		return (InstructionRecord*) NULL;

	// save actual instruction record
	InstructionRecord *tmp;
	tmp = *instructionLineIter;

	// move iterator to next instruction symbol
	instructionLineIter++;

	// return actual instruction symbol
	return tmp;
}

/**
 * Gets next instruction record without moving private iterator.
 * So if you use peek and next get -> you get same record.
 *
 * @return InstructionRecord*		pointer to the instruction record or NULL if no instruction is available
 */
IntermediateCode::InstructionRecord *IntermediateCode::peek(void) {
	if((instructionLineIter+1) == instructionLine.end())
		return (InstructionRecord*) NULL;

	return *(instructionLineIter+1);
}

/**
 * Sets internal iterator to the previous instruction record.
 */
void IntermediateCode::rollback(void) {
	if(instructionLineIter == instructionLine.begin())
		return;

	--instructionLineIter;
}

}
