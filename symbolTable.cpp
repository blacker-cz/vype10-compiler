/*
 * VYPe 2010 Compiler project
 *//**
 * Symbol table class.
 */

#include <sstream>
#include <iostream>
#include "symbolTable.h"

namespace vype10 {

/**
 * SymbolTable constructor
 */
SymbolTable::SymbolTable() {
	unnamedCounter = 0;
	nextScope = 1;
	currentScope = 0;
	previousScope = 0;
}

SymbolTable::~SymbolTable() {
	// TODO Auto-generated destructor stub
}

/**
 * Installs function into symbol table
 *
 * @param std::string*				function name
 * @param FunctionType				function type
 * @param std::vector<SymbolType>	list of symbol types
 * @param bool						flag if function is defined or declared
 * @return std::string*		key to the symbol table
 */
std::string *SymbolTable::installFunction(std::string *name, FunctionType type, std::vector<SymbolType> *types, bool defined) {
	// try to find function in table
	FunctionRecord *funRec = getFunction(name);

	/**
	 * @todo: need to output info about error type (message)
	 */

	if(funRec != (FunctionRecord*) NULL) {	// found
		if(funRec->defined == true or funRec->defined == defined)
			return (std::string*) NULL;		// already defined or trying another declaration -> return NULL pointer

		if(funRec->paramsType != *types)	// mismatch parameter types
			return (std::string*) NULL;

		if(funRec->type != type)			// mismatch function type
			return (std::string*) NULL;

		funRec->defined = true;	// set defined to true

	} else {	// not found
		funRec = new FunctionRecord;

		funRec->name = name;
		funRec->type = type;
		if(types != (std::vector<SymbolType>*) NULL)
			funRec->paramsType = *types;
		funRec->defined = defined;

		funTable.insert(std::pair<std::string, FunctionRecord*>(*name, funRec));
	}

	return name;	// name of the function is key to the table :)
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
 * @param bool				flag if identifier will be installed to this or next scope
 * @return std::string*		key to the symbol table
 */
std::string* SymbolTable::installSymbol(std::string *name, SymbolType type, bool thisScope) {
	SymbolRecord *symRec = new SymbolRecord;

	std::stringstream stream;
	std::string key, *pkey;

	stream << ":" << *name << "_" << (thisScope ? currentScope : nextScope);
	key = stream.str();
	pkey = new std::string(key);

	symRec->name = name;
	symRec->constant = false;
	symRec->scopeID = (thisScope ? currentScope : nextScope);
	symRec->type = type;

	symTable.insert(std::pair<std::string, SymbolRecord*>(key, symRec));
	return pkey;
}

/**
 * Installs list of named symbols into symbol table.
 *
 * @param std::vector<std::string*>		symbol name
 * @param SymbolType					symbol type
 */
void SymbolTable::installSymbol(std::vector<std::string*> *names, SymbolType type) {
	std::vector<std::string*>::iterator it;

	for (it = names->begin(); it != names->end(); it++) {

		SymbolRecord *symRec = new SymbolRecord;

		std::stringstream stream;
		std::string key, *pkey, *name;

		stream << ":" << **it << "_" << currentScope;
		key = stream.str();
		name = new std::string(**it);
		pkey = new std::string(key);

		symRec->name = name;
		symRec->constant = false;
		symRec->scopeID = currentScope;
		symRec->type = type;

		symTable.insert(std::pair<std::string, SymbolRecord*>(key, symRec));
	}

	// free allocated resources (vector and its content)
	delete names;
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
 * @param std::string*		key in symbol table (or identifier name)
 * @param bool				flag for recursive search in scopes if name was given
 * @return SymbolRecord*	pointer to symbol record or NULL (if not found)
 */
SymbolTable::SymbolRecord *SymbolTable::getSymbol(std::string *key, bool recursive) {
	// check if key or name of identifier was passed

	if(key->compare(0, 1, ":") == 0) {
		symTableIter = symTable.find(*key);

		if(symTableIter == symTable.end())
			return (SymbolRecord*) NULL;
	} else {
		std::stringstream stream;

		if(!recursive) {
			stream << ":" << *key << "_" << currentScope;
			symTableIter = symTable.find(stream.str());

			if(symTableIter == symTable.end())
				return (SymbolRecord*) NULL;

		} else {	// recursive search for identifier

			for(scopeStackRIter = scopeStack.rbegin(); scopeStackRIter < scopeStack.rend(); ++scopeStackRIter) {
				stream.clear();
				stream << ":" << *key << "_" << *scopeStackRIter;

				symTableIter = symTable.find(stream.str());

				if(symTableIter != symTable.end())
					return symTableIter->second;
			}
			return (SymbolRecord*) NULL;

		}
	}

	return symTableIter->second;
}

/**
 * Gets symbol record structure from symbol table (in current scope only).
 *
 * @param std::string*		key in symbol table (or identifier name)
 * @return SymbolRecord*	pointer to symbol record or NULL (if not found)
 */
SymbolTable::SymbolRecord *SymbolTable::getSymbol(std::string *key) {
	return getSymbol(key, false);
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
 * @param bool				flag for recursive search in scopes
 * @return SymbolType*		pointer to symbol type or NULL (if not found)
 */
SymbolType *SymbolTable::getSymbolType(std::string *name, bool recursive) {
	// search for symbol
	SymbolRecord *symRec = getSymbol(name, recursive);

	if(symRec == (SymbolRecord*) NULL)
		return (SymbolType*) NULL;

	return &symRec->type;
}

/**
 * Go up in scope structure.
 */
void SymbolTable::scopeUp(void) {
	previousScope = scopeStack.back();
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

/**
 * Returns current scope ID
 */
int SymbolTable::getScope(void) {
	return currentScope;
}

}