/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>
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
    int  			integerVal;
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

%type <keyString>		constant
%type <symbolType>		type_specifier
%type <functionType>	function_type
%type <namesVector>		declarator_list
%type <typesVector>		parameter_definition_list parameter_types_list

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
	: ID '=' expression
	| expression
	;

argument_expression_list
	: expression
	| argument_expression_list ',' expression
	;

constant
	: CONSTANT										{
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->intVal = $1;
														$$ = compiler.symbolTable->installConstant(vype10::SYM_INT, val);
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
	: ID
	| ID '(' ')'
	| ID '(' argument_expression_list ')'
	| PRINT '(' argument_expression_list ')'
	| STRCAT '(' expression ',' expression ')'
	| READ_CHAR '(' ')'
	| READ_SHORT '(' ')'
	| READ_INT '(' ')'
	| READ_STRING '(' ')'
	| ID '[' expression ']'
	| constant
	| expression '+' expression
	| expression '-' expression
	| expression '*' expression
	| expression '/' expression
	| expression '|' expression
	| expression '&' expression
	| expression '<' expression
	| expression '>' expression
	| expression '%' expression
	| expression AND_OP expression
	| expression OR_OP expression
	| expression EQ_OP expression
	| expression NE_OP expression
	| expression LE_OP expression
	| expression GE_OP expression
	| '!' expression %prec UNARY_OP
	| '~' expression %prec UNARY_OP
	| '(' expression ')'
	| '(' type_specifier ')' expression %prec UNARY_OP
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
	: IF '(' expression ')'
	;

/* same as if_statement */
else_statement
	: ELSE
	;

selection_statement
	: if_statement statement else_statement statement
	;

/* same as if_statement */
while_statement
	: WHILE '(' expression ')'
	;

iteration_statement
	: while_statement statement
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
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
									}
	| function_type ID '(' parameter_definition_list ')' 	{
										std::string *key;
										key = compiler.symbolTable->installFunction($2, $1, $4, true);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *$2 + "' already defined.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
	;

function_definition
	: function_head compound_statement
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
