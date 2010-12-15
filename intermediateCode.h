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

	/* Enum with possible instructions */
	typedef enum Instruction_T {FUNC_CALL, PRINT, STRCAT, READ_CHAR, READ_STRING,
		READ_INT, READ_SHORT, IF, ELSE, WHILE, CONTINUE, BREAK, RETURN, AND, OR,
		BIN_AND, BIN_OR, EQ, NE, GT, LT, GE, LE, ADD, SUB, MUL, DIV, MOD, NOT,
		BIN_NOT, INDEX} Instruction;

	void add(Instruction instruction, std::string* firstParam, std::string* secondParam, std::string* result);

private:

};

}

#endif /* INTERMEDIATECODE_H_ */
