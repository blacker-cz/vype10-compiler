/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "symbolTable.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start translation_unit

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="vype10"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &compiler.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Compiler& compiler }

/* verbose error messages */
%error-verbose

/* Include symbolTable.h to the generated header file */
%code requires {
	#include "symbolTable.h"
}

%union {
    long  			integerVal;
    char			charVal;
    std::string*	stringVal;
    std::string*	idName;
    std::string*	keyString;
    SymbolType symbolType;
	FunctionType functionType;
	std::vector<SymbolType>		*typesVector;
	
	stringpVector	*namesVector;
}

%token			END	     0		"end of file"
%token			EOL				"end of line"

%token <charVal>	CHAR_LITERAL	"character"
%token <stringVal>	STRING_LITERAL  "string"
%token <idName>		ID				"identificator"
%token <integerVal>	CONSTANT		"number constant"

%token PRINT READ_CHAR READ_SHORT READ_INT READ_STRING STRCAT

%token CHAR SHORT INT VOID STRING

%token IF ELSE WHILE CONTINUE BREAK RETURN

%left LOW_PRIORITY
%left OR_OP
%left AND_OP
%left '|'
%left '&'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left '+' '-'
%left '*' '/' '%'
%left UNARY_OP	/* unary operators */
%left HIGH_PRIORITY

%type <keyString>		constant expression
%type <symbolType>		type_specifier
%type <functionType>	function_type
%type <namesVector>		declarator_list
%type <typesVector>		parameter_definition_list parameter_types_list argument_expression_list

%{

#include "compiler.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex compiler.lexer->lex

%}

%% /*** Grammar Rules ***/

assignment_expression
	: ID '=' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								if(first == (SymbolTable::SymbolRecord*) NULL) {
									compiler.error(yylloc, "Undefined identifier '" + *$1 + "'.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type != second->type && (first->type != vype10::SYM_INT && second->type != vype10::SYM_SHORT)) {
									compiler.error(yylloc, "Mismatching types in assignment.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::ASSIGN, $3, (std::string*) NULL, compiler.symbolTable->getSymbolKey($3, true));
							}
	| expression
	;

argument_expression_list
	: expression			{
									$$ = new std::vector<SymbolType>();

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($1, true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PUSH, $1, (std::string*) NULL, (std::string*) NULL);

									$$->push_back(sym->type);
								}
	| argument_expression_list ',' expression			{

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($3, true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PUSH, $3, (std::string*) NULL, (std::string*) NULL);

									$$->push_back(sym->type);
								}
	;

print_expression_list
	: expression			{
									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($1, true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PRINT, $1, (std::string*) NULL, (std::string*) NULL);
									
								}
	| print_expression_list ',' expression			{

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($3, true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PRINT, $3, (std::string*) NULL, (std::string*) NULL);
								}
	;

constant
	: CONSTANT										{
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->intVal = $1;
														if($1 >= SHRT_MIN && $1 <= SHRT_MAX) {
															$$ = compiler.symbolTable->installConstant(vype10::SYM_SHORT, val);
														} else {
															$$ = compiler.symbolTable->installConstant(vype10::SYM_INT, val);
														}
													}
	| CHAR_LITERAL									{
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->charVal = $1;
														$$ = compiler.symbolTable->installConstant(vype10::SYM_CHAR, val);
													}
	| STRING_LITERAL								{
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->stringVal = $1;
														$$ = compiler.symbolTable->installConstant(vype10::SYM_STRING, val);
													}
	;	

expression
	: ID											{
														$$ = compiler.symbolTable->getSymbolKey($1, true);
														if($$ == (std::string*) NULL) {
															compiler.error(yylloc, "Undefined identifier '" + *$1 + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
													}
	| ID '(' ')'									{
														SymbolTable::FunctionRecord *fun = compiler.symbolTable->getFunction($1);
														if(fun == (SymbolTable::FunctionRecord*) NULL) {
															compiler.error(yylloc, "Call of undefined/undeclared function '" + *$1 + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->paramsType.size() != 0) {
															compiler.error(yylloc, "Function '" + *$1 + "' expect " + (char) ('0' + (int)fun->paramsType.size()) + " params, none given.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->type != vype10::FUN_VOID) {
															$$ = compiler.symbolTable->installSymbol((vype10::SymbolType) fun->type);
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, $1, (std::string*) NULL, $$);
														} else {
															$$ = (std::string*) NULL;
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, $1, (std::string*) NULL, (std::string*) NULL);
														}
													}
	| ID '(' argument_expression_list ')'			{
														SymbolTable::FunctionRecord *fun = compiler.symbolTable->getFunction($1);
														if(fun == (SymbolTable::FunctionRecord*) NULL) {
															compiler.error(yylloc, "Call of undefined/undeclared function '" + *$1 + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->paramsType != *$3) {
															compiler.error(yylloc, "Invalid arguments passed to function '" + *$1 + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->type != vype10::FUN_VOID) {
															$$ = compiler.symbolTable->installSymbol((vype10::SymbolType) fun->type);
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, $1, (std::string*) NULL, $$);
														} else {
															$$ = (std::string*) NULL;
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, $1, (std::string*) NULL, (std::string*) NULL);
														}
													}
	| PRINT '(' print_expression_list ')'			{ $$ = (std::string*) NULL; }
	| STRCAT '(' expression ',' expression ')'		{
														SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($3, true);
														if(first->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "First parameter must be of type string.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($5, true);
														if(second->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "Second parameter must be of type string.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
														compiler.intermediateCode->add(vype10::IntermediateCode::STRCAT, $3, $5, $$);
													}
	| READ_CHAR '(' ')'								{
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_CHAR);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_CHAR, (std::string*)NULL, (std::string*)NULL, $$);
													}
	| READ_SHORT '(' ')'								{
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_SHORT, (std::string*)NULL, (std::string*)NULL, $$);
													}
	| READ_INT '(' ')'								{
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_INT, (std::string*)NULL, (std::string*)NULL, $$);
													}
	| READ_STRING '(' ')'							{
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_STRING, (std::string*)NULL, (std::string*)NULL, $$);
													}
	| ID '[' expression ']'							{
														SymbolTable::SymbolRecord *id = compiler.symbolTable->getSymbol($1, true);
														if(id == (SymbolTable::SymbolRecord*) NULL) {
															compiler.error(yylloc, "Undefined identifier '" + *$1 + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(id->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "Only strings allow array access.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($3, true);
														if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
															compiler.error(yylloc, "Index must be of type short or int.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														$$ = compiler.symbolTable->installSymbol(vype10::SYM_CHAR);
														compiler.intermediateCode->add(vype10::IntermediateCode::INDEX, compiler.symbolTable->getSymbolKey($1, true), $3, $$);
													}
	| constant
	| expression '+' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '+' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::ADD, $1, $3, $$);
							}
	| expression '-' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '-' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::SUB, $1, $3, $$);
							}
	| expression '*' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '*' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::MUL, $1, $3, $$);
							}
	| expression '/' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '/' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::DIV, $1, $3, $$);
							}
	| expression '|' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression '&' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression '<' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '<' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression '>' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '>' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression '%' expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
								} else {
									compiler.error(yylloc, "Invalid types in '%' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::MOD, $1, $3, $$);
							}
	| expression AND_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '&&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression OR_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '||' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression EQ_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '==' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression NE_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '!=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression LE_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '<=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| expression GE_OP expression		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($1, true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol($3, true);
								if(first->type == second->type) {	// ok
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, $1, $3, $$);
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $3, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, $1, pom, $$);
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $1, (std::string*) NULL, pom);
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, pom, $3, $$);
								} else {
									compiler.error(yylloc, "Invalid types in '>=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| '!' expression %prec UNARY_OP		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($2, true);
								if(first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NOT, $2, (std::string*) NULL, $$);
								} else {
									compiler.error(yylloc, "Invalid type in '!' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| '~' expression %prec UNARY_OP		{
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol($2, true);
								if(first->type == vype10::SYM_INT) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_NOT, $2, (std::string*) NULL, $$);
								} else if(first->type == vype10::SYM_SHORT) {
									$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_NOT, $2, (std::string*) NULL, $$);
								} else {
									compiler.error(yylloc, "Invalid type in '~' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
	| '(' expression ')'							{ $$ = $2; }
	| '(' type_specifier ')' expression %prec HIGH_PRIORITY		{
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($4, true);
										if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
											compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
											YYERROR;
										}
										
										if(sym->type == $2) {	// same type -> do nothing
										} else if(sym->type == vype10::SYM_CHAR && $2 == vype10::SYM_STRING) {	// char -> string
											$$ = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $4, (std::string*) NULL, $$);
										} else if(sym->type == vype10::SYM_CHAR && $2 == vype10::SYM_SHORT) {	// char -> short
											$$ = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $4, (std::string*) NULL, $$);
										} else if(sym->type == vype10::SYM_CHAR && $2 == vype10::SYM_INT) {		// char -> int
											$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $4, (std::string*) NULL, $$);
										} else if(sym->type == vype10::SYM_SHORT && $2 == vype10::SYM_INT) {	// short -> int
											$$ = compiler.symbolTable->installSymbol(vype10::SYM_INT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, $4, (std::string*) NULL, $$);
										} else {
											compiler.error(yylloc, "Invalid cast.", RET_ERR_INTERNAL);
											YYERROR;
										}
 									}
	;

declaration
	: type_specifier declarator_list ';'	{ compiler.symbolTable->installSymbol($2, $1); }
	;

declarator_list
	: ID						{
									$$ = new std::vector<std::string*>();
									if(compiler.symbolTable->getSymbol($1) != (SymbolTable::SymbolRecord*) NULL || compiler.symbolTable->getFunction($1) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier with name '" + *$1 + "' already defined.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									if(compiler.symbolTable->getFunction($1) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *$1 + "' can't have same name as defined/declared function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									$$->push_back($1);
								}
	| declarator_list ',' ID	{
									if(compiler.symbolTable->getSymbol($3) != (SymbolTable::SymbolRecord*) NULL) {
										compiler.error(yylloc, "Identifier with name '" + *$3 + "' already defined.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									if(compiler.symbolTable->getFunction($3) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *$3 + "' can't have same name as defined/declared function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									$$->push_back($3); 
								}
	;

function_type
	: VOID		{ $$ = vype10::FUN_VOID; }
	| CHAR		{ $$ = vype10::FUN_CHAR; }
	| SHORT		{ $$ = vype10::FUN_SHORT; }
	| INT		{ $$ = vype10::FUN_INT; }
	| STRING	{ $$ = vype10::FUN_STRING; }
	;

type_specifier
	: CHAR		{ $$ = vype10::SYM_CHAR; }
	| SHORT		{ $$ = vype10::SYM_SHORT; }
	| INT		{ $$ = vype10::SYM_INT; }
	| STRING	{ $$ = vype10::SYM_STRING; }
	;
	
parameter_types_list
	: type_specifier			{
									$$ = new std::vector<SymbolType>();
									// no check needed
									$$->push_back($1);
								}
	| parameter_types_list ',' type_specifier	{
									// no check needed
									$$->push_back($3); 
								}
	;
	
parameter_definition_list
	: type_specifier ID			{
									$$ = new std::vector<SymbolType>();
									if(compiler.symbolTable->getFunction($2) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *$2 + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									compiler.symbolTable->installSymbol($2, $1, false);
									$$->push_back($1);
								}
	| parameter_definition_list ',' type_specifier ID	{
									if(compiler.symbolTable->getFunction($4) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *$4 + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									compiler.symbolTable->installSymbol($4, $3, false);
									$$->push_back($3); 
								}
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

statement_list
	: statement
	| statement_list statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

expression_statement
	: ';'
	| assignment_expression ';'
	;

/* unattached from selection statement because of need to generate intermediate symbols before reduction of whole selection_statement
	-> i am not so sure about this anymore, but it works :)  */
if_statement
	: IF '(' expression ')'			{
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($3, true);
										if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
											compiler.error(yylloc, "Expression must be of type short or int.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
										compiler.intermediateCode->add(vype10::IntermediateCode::IF, compiler.symbolTable->getSymbolKey($3, true), (std::string*) NULL,  (std::string*) NULL);
									}
	;

/* same as if_statement */
else_statement
	: ELSE							{
										compiler.intermediateCode->add(vype10::IntermediateCode::ELSE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
	;

selection_statement
	: if_statement statement else_statement statement	{
										compiler.intermediateCode->add(vype10::IntermediateCode::ENDIF, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
	;

/* same as if_statement */
while_statement
	: WHILE '(' expression ')'		{
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol($3, true);
										if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
											compiler.error(yylloc, "Expression must be of type short or int.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
										compiler.intermediateCode->add(vype10::IntermediateCode::WHILE, compiler.symbolTable->getSymbolKey($3, true), (std::string*) NULL,  (std::string*) NULL);
									}
	
	;

iteration_statement
	: while_statement statement	{
									compiler.intermediateCode->add(vype10::IntermediateCode::ENDWHILE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
	;

jump_statement
	: CONTINUE ';'				{
									compiler.intermediateCode->add(vype10::IntermediateCode::CONTINUE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
	| BREAK ';'					{
									compiler.intermediateCode->add(vype10::IntermediateCode::BREAK, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
	| RETURN ';'				{
									compiler.intermediateCode->add(vype10::IntermediateCode::RETURN, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
	| RETURN expression ';'		{
									compiler.intermediateCode->add(vype10::IntermediateCode::RETURN, $2, (std::string*) NULL,  (std::string*) NULL);
								}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_declaration
	| function_definition
	;

/* separated from function_definition because of need to generate intermediate code for function header before reduction of whole function
	-> i am not so sure about this anymore, but it works :) */
function_head
	: function_type ID '(' VOID ')'	{
										std::string *key;
										key = compiler.symbolTable->installFunction($2, $1, (std::vector<SymbolType>*) NULL, true);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *$2 + "' already defined.", RET_ERR_SEMANTICAL);
											YYERROR;
										}

										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_DEF, key, (std::string*) NULL,  (std::string*) NULL);
									}
	| function_type ID '(' parameter_definition_list ')' 	{
										std::string *key;
										key = compiler.symbolTable->installFunction($2, $1, $4, true);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *$2 + "' already defined.", RET_ERR_SEMANTICAL);
											YYERROR;
										}

										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_DEF, key, (std::string*) NULL,  (std::string*) NULL);
									}
	;

function_definition
	: function_head compound_statement {
										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_END, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
	;

function_declaration
	: function_type ID '(' VOID ')' ';'	{
										std::string *key;
										key = compiler.symbolTable->installFunction($2, $1, (std::vector<SymbolType>*) NULL, false);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *$2 + "' already defined (or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
	| function_type ID '(' parameter_types_list ')' ';'		{
										std::string *key;
										key = compiler.symbolTable->installFunction($2, $1, $4, false);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *$2 + "' already defined (or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
	;

%% /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m, RET_ERR_SYNTACTICAL);
}
