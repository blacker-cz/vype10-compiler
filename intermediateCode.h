/*
 * VYPe 2010 Compiler project
 *//**
 * Intermediate code class.
 */

#ifndef INTERMEDIATECODE_H_
#define INTERMEDIATECODE_H_

#include <vector>
#include <string>

namespace vype10 {

class IntermediateCode {
public:
	IntermediateCode();
	virtual ~IntermediateCode();

	/** Enum with possible instructions */
	typedef enum Instruction_T {FUNC_CALL = 0, PRINT, STRCAT, READ_CHAR, READ_STRING,
		READ_INT, READ_SHORT, IF, ELSE, WHILE, CONTINUE, BREAK, RETURN, AND, OR,
		BIN_AND, BIN_OR, EQ, NE, GT, LT, GE, LE, ADD, SUB, MUL, DIV, MOD, NOT,
		BIN_NOT, INDEX, NOP, ASSIGN, CAST, ENDIF, ENDWHILE, PUSH} Instruction;

	/** Structure for keeping instruction record */
	typedef struct InstructionRecord_T {
		Instruction 	instruction;
		std::string*	first;
		std::string*	second;
		std::string*	result;

		InstructionRecord_T() {
			instruction = NOP;
			first = (std::string*) NULL;
			second = (std::string*) NULL;
			result = (std::string*) NULL;
		}
	} InstructionRecord;

	void add(Instruction instruction, std::string* firstParam, std::string* secondParam, std::string* result);

	InstructionRecord *get(void);

	InstructionRecord *peek(void);

	void rollback(void);

private:
	/** Vector for keeping instruction line */
	std::vector<InstructionRecord*> instructionLine;

	/** Iterator for instruction line vector */
	std::vector<InstructionRecord*>::iterator instructionLineIter;
};

}

#endif /* INTERMEDIATECODE_H_ */