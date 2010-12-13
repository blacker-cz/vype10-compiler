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

class SymbolTable {

public:
	SymbolTable();
	virtual ~SymbolTable();

	typedef enum SymbolType_T {SYM_INT, SYM_SHORT, SYM_CHAR, SYM_STRING} SymbolType;
	typedef enum FunctionType_T {FUN_INT, FUN_SHORT, FUN_CHAR, FUN_STRING, FUN_VOID} FunctionType;

	/** Union for storing constants value */
	typedef union value_t {
		int intVal;
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
		std::vector<SymbolType> paramsType;

		/** Structure destructor */
		~funRecord() {
			delete name;
		}
	} FunctionRecord;

	std::string *installFunction(std::string *name, FunctionType type, ...);

	bool addFunctionParam(std::string *name, SymbolType type);

	std::string *installSymbol(std::string *name, SymbolType type);

	std::string *installSymbol(SymbolType type);

	std::string *installConstant(SymbolType type, Value *value);

	SymbolRecord *getSymbol(std::string *key);

	FunctionRecord *getFunction(std::string *key);

	SymbolType *getSymbolType(std::string *name);

	void scopeUp(void);

	void scopeDown(void);

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
	/** Private scope stack iterator*/
	std::vector<int> scopeStackIter;

	/** Current scope ID */
	int currentScope;

	/** Next available scope ID */
	int nextScope;

	/** Special counter used for unnamed identifiers */
	int unnamedCounter;
};

}

#endif /* SYMBOLTABLE_H_ */
