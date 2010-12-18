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

	/**
	 * @todo: implement this
	 */

	// generate header of assembly file
	head();

	IntermediateCode::InstructionRecord *instruction = intermediateCode->get();
	if(instruction == (IntermediateCode::InstructionRecord*) NULL) {
		compiler->error("This shouldn't happen.", RET_ERR_INTERNAL);
		return;
	}

	// processing instruction line
	do {
		if(!process(instruction))
			return;

		instruction = intermediateCode->get();
	} while (instruction != (IntermediateCode::InstructionRecord*) NULL);

	// generate data section of assembly file
	data();

	output.close();
}

/**
 * Generates head of the output asm file.
 */
void CodeGenerator::head(void) {
	comment("Auto-generated asm file");
	comment("Used registers:");
	comment("\t$sp - stack pointer");
	comment("\t$25 - data area pointer");
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
	command("li $sp, stack");
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
	label("stack:\t.space\t" << 1024*4);
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

	// constants processing
	std::vector<std::string*> *id = compiler->symbolTable->getIdentifiers();
	for(size_t i=0; i < constants->size(); i++) {
		symRec = compiler->symbolTable->getSymbol((*id)[i], true);

		switch(symRec->type) {
			case SYM_CHAR:
					label(generateName(symRec->key) << ":\t" << ".byte\t" << 0);
				break;
			case SYM_INT:
					label(generateName(symRec->key) << ":\t" << ".int\t" << 0);
				break;
			case SYM_SHORT:
					label(generateName(symRec->key) << ":\t" << ".short\t" << 0);
				break;
			case SYM_STRING:
					label(generateName(symRec->key) << ":\t" << ".word\t" << 0);
				break;
			default:
				break;
		}
	}
	id->clear();
	delete id;
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
}

}
