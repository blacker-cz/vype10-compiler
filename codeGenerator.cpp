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
 * @param std::string			path to the output file
 */
CodeGenerator::CodeGenerator(IntermediateCode *intermediateCode, std::string output) {
	this->intermediateCode = intermediateCode;
	this->output.open(output.c_str(), std::ios_base::out | std::ios_base::trunc);

	// push free registers in to queue
	this->free.push("$8");
	this->free.push("$9");
	this->free.push("$10");
	this->free.push("$11");
	this->free.push("$12");
	this->free.push("$13");
	this->free.push("$14");
	this->free.push("$15");
	this->free.push("$16");
	this->free.push("$17");
	this->free.push("$18");
	this->free.push("$19");
	this->free.push("$20");
	this->free.push("$21");
	this->free.push("$22");
	this->free.push("$23");
}

CodeGenerator::~CodeGenerator() {
}

/**
 * Method which starts assembler generation.
 */
void CodeGenerator::run(void) {

	// check if output file is open
	if(!this->output.good()) {
		compiler->error("Couldn't open output file.", RET_ERR_INTERNAL);
		return;
	}

	// generate header of assembly file
	head();
	intermediateCode->lock();

	IntermediateCode::InstructionRecord *instruction = intermediateCode->get();
	if(instruction == (IntermediateCode::InstructionRecord*) NULL) {
		compiler->error("This shouldn't happen.", RET_ERR_INTERNAL);
		return;
	}

	try {

		// processing instruction line
		do {
			if(!process(instruction))
				return;

			instruction = intermediateCode->get();
		} while (instruction != (IntermediateCode::InstructionRecord*) NULL);

	} catch(ProcessingException &ex) {
		compiler->error(ex.msg, ex.code);
		return;
	}

	// generate data section of assembly file
	data();

	// flush and close output file
	output.close();
}

/**
 * Generates head of the output asm file.
 */
void CodeGenerator::head(void) {
	comment("Auto-generated asm file");
	comment("Used registers:");
	comment("\t$sp - stack pointer - data stack top");
	comment("\t$30 - call stack top");
	comment("\t$25 - end of data area pointer");
	comment("Program code section:");
	comment("---------------------------------------------------");
	command(".text");
	command(".org 0");
	command("nop");
	command("nop");
	command("nop");
	command("nop");
	command("li $25, dataset");
	command("sw $0, 0($25)");
	command("addi $25, $25, 4");
	command("li $sp, datastack");
	command("li $30, callstack");
	command("jaL fun_main");
	command("break");
}

/**
 * Generates data section of output asm file.
 */
void CodeGenerator::data(void) {
	comment("Data section:");
	comment("---------------------------------------------------");
	command(".data");
	label("callstack:\t.space\t" << 1024*4);
	label("datastack:\t.space\t" << 1024*4);
	label("dataset:\t.space\t" << 1024*32);

	SymbolTable::SymbolRecord *symRec;

	// constants processing
	std::vector<std::string*> *constants = compiler->symbolTable->getConstants();
	for(size_t i=0; i < constants->size(); i++) {
		symRec = compiler->symbolTable->getSymbol((*constants)[i], true);

		switch(symRec->type) {
			case SYM_CHAR:
				switch(symRec->value->charVal) {
					case '\t':
						label(generateName(symRec->key) << ":\t" << ".byte\t" << (int)'\t');
						break;
					case '\n':
						label(generateName(symRec->key) << ":\t" << ".byte\t" << (int)'\n');
						break;
					case '\'':
						label(generateName(symRec->key) << ":\t" << ".byte\t" << (int)'\'');
						break;
					case '\\':
						label(generateName(symRec->key) << ":\t" << ".byte\t" << (int)'\\');
						break;
					default:
						label(generateName(symRec->key) << ":\t" << ".byte\t" << (int) symRec->value->charVal);
						break;
				}
				break;
			case SYM_INT:
					label(generateName(symRec->key) << ":\t" << ".int\t" << symRec->value->intVal);
				break;
			case SYM_SHORT:
					label(generateName(symRec->key) << ":\t" << ".short\t" << symRec->value->intVal);
				break;
			case SYM_STRING:
					label(generateName(symRec->key) << ":\t" << ".ascii\t\"" << *symRec->value->stringVal << "\\000\"");
				break;
			default:
				break;
		}
	}
	// cleanup
	constants->clear();
	delete constants;
}

/**
 * Generates asm names for symbol table records.
 *
 * @param std::string	symbol table record key
 * @return				asm symbol name
 */
std::string CodeGenerator::generateName(std::string key) {
	std::replace(key.begin(), key.end(), ':', '_');
	return key;
}

/**
 * Process single instruction and generates it's code.
 * This is generally only one big switch statement :)
 */
bool CodeGenerator::process(IntermediateCode::InstructionRecord* instruction) {
	/**
	 * @todo: implement this
	 */

	switch(instruction->instruction) {
	case IntermediateCode::FUNC_CALL:
		break;
	case IntermediateCode::PRINT:
	case IntermediateCode::STRCAT:
	case IntermediateCode::READ_CHAR:
	case IntermediateCode::READ_STRING:
	case IntermediateCode::READ_INT:
	case IntermediateCode::READ_SHORT:
	case IntermediateCode::IF:
	case IntermediateCode::ELSE:
	case IntermediateCode::WHILE:
	case IntermediateCode::CONTINUE:
	case IntermediateCode::BREAK:
	case IntermediateCode::RETURN:
	case IntermediateCode::AND:
	case IntermediateCode::OR:
	case IntermediateCode::BIN_AND:
	case IntermediateCode::BIN_OR:
	case IntermediateCode::EQ:
	case IntermediateCode::NE:
	case IntermediateCode::GT:
	case IntermediateCode::LT:
	case IntermediateCode::GE:
	case IntermediateCode::LE:
	case IntermediateCode::ADD:
	case IntermediateCode::SUB:
	case IntermediateCode::MUL:
	case IntermediateCode::DIV:
	case IntermediateCode::MOD:
	case IntermediateCode::NOT:
	case IntermediateCode::BIN_NOT:
	case IntermediateCode::INDEX:
	case IntermediateCode::NOP:
	case IntermediateCode::ASSIGN:
	case IntermediateCode::CAST:
	case IntermediateCode::ENDIF:
	case IntermediateCode::ENDWHILE:
	case IntermediateCode::PUSH:
	case IntermediateCode::FUNC_DEF:
	case IntermediateCode::FUNC_END:
	default:
		return true;
	}

	return true;
}

/**
 * Get register depending on symbol table key.
 *
 * @param std::string		symbol table key
 * @return std::string		free register
 */
std::string CodeGenerator::getRegister(std::string key) {

	// if key is for constant -> load to register and return
	if(key.compare(0, 7, ":const:") == 0) {
		// TODO
	}

	cleanUsed();

	// look if isn't already used
	usedIter = used.find(key);
	if(usedIter != used.end()) {
		--usedIter->second->remaining;
		return usedIter->second->reg;
	}

	// look if isn't saved on stack
	if(searchSaved(key)) {
		SavedInfo *popped;
		do {
			popped = saved.back();
			saved.pop_back();

			if(free.size() == 0)
				throw new ProcessingException(RET_ERR_GENERATION, "No free registers available.");

			UsedInfo* info = new UsedInfo;
			info->reg = free.front();
			free.pop();
			info->remaining = popped->key.compare(key) == 0 ? popped->remaining - 1 : popped->remaining;

			command("addi $sp, $sp, -4");
			command("lw " << info->reg << ", 0($sp)");

			used.insert(std::pair<std::string, UsedInfo*>(popped->key, info));
			if(popped->key.compare(key) == 0)
				return info->reg;
		} while(true);
	}

	// check if we have enough available registers
	while(free.size() < 5) {	// no -> free some (save to stack)
		std::string lu = leastUsed();
		usedIter = used.find(key);
		SavedInfo *sinfo = new SavedInfo;
		sinfo->key = lu;
		sinfo->remaining = usedIter->second->remaining;
		saved.push_back(sinfo);

		command("sw " << usedIter->second->reg << ", 0($sp)");
		command("addi $sp, $sp, 4");

		used.erase(usedIter);
	}

	// allocate new register
	UsedInfo* info = new UsedInfo;
	SymbolTable::SymbolRecord *symRec = compiler->symbolTable->getSymbol(&key);
	info->reg = free.front();
	free.pop();
	info->remaining = symRec->timesUsed - 1;
	used.insert(std::pair<std::string, UsedInfo*>(key, info));

	return info->reg;
}

/**
 * Search if variable is saved on the stack.
 *
 * @return bool		if variable is saved somewhere on stack
 */
bool CodeGenerator::searchSaved(std::string key) {
	for(savedIter = saved.begin(); savedIter != saved.end(); savedIter++) {
		if((*savedIter)->key.compare(key) == 0)
			return true;
	}
	return false;
}

/**
 * Return variable key for variable which should be saved to stack.
 *
 * @return std::string		key of variable witch should be saved to stack
 */
std::string CodeGenerator::leastUsed(void) {
	int min = 65536;	// magic constant
	std::string key;

	for(usedIter = used.begin(); usedIter != used.end(); usedIter++) {
		if(usedIter->second->remaining < min) {
			key = usedIter->first;
			min = usedIter->second->remaining;
		}
	}

	return key;
}

/**
 * Removes variables which will no longer be used.
 */
void CodeGenerator::cleanUsed(void) {
	for(usedIter = used.begin(); usedIter != used.end();) {
		if(usedIter->second->remaining < 1) {
			free.push(usedIter->second->reg);
			used.erase(usedIter++);
		} else {
			++usedIter;
		}
	}
}

}
