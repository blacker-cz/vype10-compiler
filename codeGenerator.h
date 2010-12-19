/*
 * VYPe 2010 Compiler project
 *//**
 * Assembler code generation class.
 * @author: Lukáš Černý <xcerny37@stud.fit.vutbr.cz>
 */

#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include <string>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include "intermediateCode.h"
#include "compiler.h"

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

	/** Struct for keeping information about registers saved to stack */
	typedef struct savedInfo_T {
		std::string key;
		int remaining;
	} SavedInfo;

	/** Struct for keeping information about in use registers */
	typedef struct usedInfo_T {
		std::string reg;
		int remaining;
	} UsedInfo;

	/** Queue of free (temporary) variable registers */
	std::queue<std::string> free;

	/** Vector of saved (temporary) variable registers */
	std::vector<SavedInfo*> saved;
	/** Vector of saved (temporary) variable registers - iterator */
	std::vector<SavedInfo*>::iterator savedIter;

	/** Map of in use (temporary) variable registers */
	std::map<std::string, UsedInfo*> used;
	/** Map of in use (temporary) variable registers - iterator */
	std::map<std::string, UsedInfo*>::iterator usedIter;

	void head(void);

	void data(void);

	std::string generateName(std::string);

	bool process(IntermediateCode::InstructionRecord* instruction);

	std::string getRegister(std::string);

	bool searchSaved(std::string key);

	std::string leastUsed(void);

	void cleanUsed(void);

};

}

#endif /* CODEGENERATOR_H_ */
