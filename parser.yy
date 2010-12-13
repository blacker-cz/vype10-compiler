/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>

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

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
    int  			integerVal;
    char			charVal;
    std::string*	stringVal;
    std::string*	idName;
}

%token			END	     0		"end of file"
%token			EOL				"end of line"

%token <charVal>	CHAR_LITERAL	"character"
%token <stringVal>	STRING_LITERAL  "string"
%token <idName>		ID				"identificator"
%token <integerVal>	CONSTANT		"number constant"

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

/*%type <calcnode>	constant variable
%type <calcnode>	atomexpr powexpr unaryexpr mulexpr addexpr expr*/

/*%destructor { delete $$; } STRING_LITERAL
%destructor { delete $$; } constant variable
%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr expr*/

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

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

expression
	: ID											{ std::cerr << "Identifier: " << *$1 << std::endl; }
	| CONSTANT										{ std::cerr << "Int constant: " << $1 << std::endl; }
	| CHAR_LITERAL									{ std::cerr << "Character literal: " << $1 << std::endl; }
	| STRING_LITERAL								{ std::cerr << "String literal: " << *$1 << std::endl; }
	| ID '(' ')'
	| ID '(' argument_expression_list ')'			{ std::cerr << "Function call: " << *$1 << std::endl; }
	| ID '[' expression ']'
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
	: type_specifier declarator_list ';'
	;

declarator_list
	: ID
	| declarator_list ',' ID
	;

function_type
	: VOID
	| CHAR
	| SHORT
	| INT
	| STRING
	;

type_specifier
	: CHAR
	| SHORT
	| INT
	| STRING
	;
	
parameter_types_list
	: type_specifier
	| parameter_types_list ',' type_specifier
	;
	
parameter_definition_list
	: type_specifier ID
	| parameter_definition_list ',' type_specifier ID
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

selection_statement
	: /*IF '(' expression ')' statement
	|*/ IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
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

function_definition
	: function_type ID '(' VOID ')' compound_statement
	| function_type ID '(' parameter_definition_list ')' compound_statement
	;

function_declaration
	: function_type ID '(' VOID ')' ';'
	| function_type ID '(' parameter_types_list ')' ';'
	;

%% /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m, RET_ERR_SYNTACTICAL);
}
