/*
 * VYPe 2010 Compiler project
 *//**
 * Symbol table class.
 */

#include <sstream>
#include "symbolTable.h"

namespace vype10 {

/**
 * SymbolTable constructor
 */
SymbolTable::SymbolTable() {
	unnamedCounter = 0;
	nextScope = 1;
	currentScope = 0;

	scopeStack.push_back(currentScope);
}

SymbolTable::~SymbolTable() {
	// TODO Auto-generated destructor stub
}

/**
 * Installs function into symbol table
 *
 * @param std::string*		function name
 * @param FunctionType		function type
 * @param ...				function params (SymbolType)
 * @return std::string*		key to the symbol table
 */
std::string *SymbolTable::installFunction(std::string *name, FunctionType type, ...) {
	/** @todo implement this */
	return (std::string*) NULL;
}

/**
 * Add parameter to specified function after installation.
 * Works with stack so later added parameters are appended to the end or parameter list.
 *
 * @param std::string*		function name or key to the symbol table
 * @param SymbolType		type of symbol
 */
bool SymbolTable::addFunctionParam(std::string *name, SymbolType type) {
	/** @todo implement this */
	return false;
}

/**
 * Installs unnamed symbol into symbol table.
 *
 * @param SymbolType	symbol type
 * @return std::string*		key to the symbol table
 */
std::string* SymbolTable::installSymbol(SymbolType type) {
	SymbolRecord *symRec = new SymbolRecord;

	std::stringstream stream;
	std::string name, *pname, *key;

	stream << ":" << unnamedCounter++ << "_" << currentScope;
	name = stream.str();
	pname = new std::string(name);
	key = new std::string(name);

	symRec->name = pname;
	symRec->constant = false;
	symRec->scopeID = currentScope;
	symRec->type = type;

	symTable.insert(std::pair<std::string, SymbolRecord*>(*key, symRec));
	return key;
}

/**
 * Installs named symbol into symbol table.
 *
 * @param std::string*		symbol name
 * @param SymbolType		symbol type
 * @return std::string*		key to the symbol table
 */
std::string* SymbolTable::installSymbol(std::string *name, SymbolType type) {
	SymbolRecord *symRec = new SymbolRecord;

	std::stringstream stream;
	std::string key, *pkey;

	stream << ":" << *name << "_" << currentScope;
	key = stream.str();
	pkey = new std::string(key);

	symRec->name = name;
	symRec->constant = false;
	symRec->scopeID = currentScope;
	symRec->type = type;

	symTable.insert(std::pair<std::string, SymbolRecord*>(key, symRec));
	return pkey;
}

/**
 * Installs constant into symbol table
 *
 * @param SymbolType		constant type
 * @param Value*			constant value
 * @return std::string*		key to the symbol table
 */
std::string *SymbolTable::installConstant(SymbolType type, Value *value) {
	SymbolRecord *symRec = new SymbolRecord;

	std::stringstream stream;
	std::string name, *pname, *key;

	stream << ":" << unnamedCounter++ << "_" << currentScope;
	name = stream.str();
	pname = new std::string(name);
	key = new std::string(name);

	symRec->name = pname;
	symRec->constant = true;
	symRec->scopeID = currentScope;
	symRec->type = type;
	symRec->value = value;

	symTable.insert(std::pair<std::string, SymbolRecord*>(*key, symRec));
	return key;
}

/**
 * Gets symbol record structure from symbol table.
 *
 * @param std::string*		key in symbol table
 * @return SymbolRecord*	pointer to symbol record or NULL (if not found)
 */
SymbolTable::SymbolRecord *SymbolTable::getSymbol(std::string *key) {
	symTableIter = symTable.find(*key);

	if(symTableIter == symTable.end())
		return (SymbolRecord*) NULL;

	return symTableIter->second;
}

/**
 * Gets function record structure from symbol table
 *
 * @param std::string*		key in symbol table
 * @return FunctionRecord*	pointer to function record or NULL (if not found)
 */
SymbolTable::FunctionRecord *SymbolTable::getFunction(std::string *key) {
	funTableIter = funTable.find(*key);

	if(funTableIter == funTable.end())
		return (FunctionRecord*) NULL;

	return funTableIter->second;
}

/**
 * Gets symbol type for specified symbol
 *
 * @param std::string*		symbol name or key
 * @return SymbolType*		pointer to symbol type or NULL (if not found)
 */
SymbolTable::SymbolType *SymbolTable::getSymbolType(std::string *name) {
	/** @todo implement this need to resolve if key or name!! */
	return (SymbolType*) NULL;
}

/**
 * Go up in scope structure.
 */
void SymbolTable::scopeUp(void) {
	scopeStack.pop_back();
	currentScope = scopeStack.back();
}

/**
 * Go down in scope structure.
 */
void SymbolTable::scopeDown(void) {
	currentScope = nextScope++;
	scopeStack.push_back(currentScope);
}

}
