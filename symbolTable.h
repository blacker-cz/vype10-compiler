/*
 * VYPe 2010 Compiler project
 *//**
 * Symbol table class.
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>
#include <vector>

namespace vype10 {

typedef enum SymbolType_T {SYM_INT = 0, SYM_SHORT, SYM_CHAR, SYM_STRING} SymbolType;
typedef enum FunctionType_T {FUN_INT = 0, FUN_SHORT, FUN_CHAR, FUN_STRING, FUN_VOID} FunctionType;

typedef std::vector<std::string*>	stringpVector;

class SymbolTable {

public:
	SymbolTable();
	virtual ~SymbolTable();

	/** Union for storing constants value */
	typedef union value_t {
		long intVal;
		std::string *stringVal;
		char charVal;
	} Value;

	/** Structure for informations about symbol */
	typedef struct symRecord {
		std::string *name;
		bool constant;
		SymbolType type;
		int scopeID;
		Value *value;
		std::string key;

		/** Structure destructor */
		~symRecord() {
			delete name;
			if(type == SYM_STRING)
				delete value->stringVal;
			delete value;
		}
	} SymbolRecord;

	/** Structure for informations about function */
	typedef struct funRecord {
		std::string *name;
		FunctionType type;
		bool defined;
		std::vector<SymbolType> paramsType;
		std::string key;

		/** Structure destructor */
		~funRecord() {
			delete name;
		}
	} FunctionRecord;

	std::string *installFunction(std::string *name, FunctionType type, std::vector<SymbolType> *types, bool defined, std::string & error);

	std::string* installSymbol(std::string *name, SymbolType type, bool thisScope);

	void installSymbol(std::vector<std::string*> *names, SymbolType type);

	std::string *installSymbol(SymbolType type);

	std::string *installConstant(SymbolType type, Value *value);

	SymbolRecord *getSymbol(std::string *key, bool recursive);

	SymbolRecord *getSymbol(std::string *key);

	std::string *getSymbolKey(std::string *key, bool recursive);

	std::string *getSymbolKey(std::string *key);

	FunctionRecord *getFunction(std::string *key);

	SymbolType *getSymbolType(std::string *name, bool recursive);

	std::string *getUndefinedFunctions(void);

	std::vector<std::string*> *getConstants(void);

	std::vector<std::string*> *getIdentifiers(void);

	void scopeUp(void);

	void scopeDown(void);

	int getScope(void);

private:
	/** Private map of symbols */
	std::map<std::string, SymbolRecord*> symTable;
	/** Iterator for private map of symbols */
	std::map<std::string, SymbolRecord*>::iterator symTableIter;

	/** Private map of functions */
	std::map<std::string, FunctionRecord*> funTable;
	/** Iterator for private map of functions */
	std::map<std::string, FunctionRecord*>::iterator funTableIter;

	/** Private scope stack (using vector for reading records lower on stack without need to pop) */
	std::vector<int> scopeStack;
	/** Private scope stack reverse iterator*/
	std::vector<int>::reverse_iterator scopeStackRIter;

	/** Current scope ID */
	int currentScope;

	/** Next available scope ID */
	int nextScope;

	/** Previous scope ID */
	int previousScope;

	/** Special counter used for unnamed identifiers */
	int unnamedCounter;
};

}

#endif /* SYMBOLTABLE_H_ */
