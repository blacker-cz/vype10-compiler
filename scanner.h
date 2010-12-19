/*
 * VYPe 2010 Compiler project
 *//**
 * Header file for generated scanner class.
 * @author: Lukáš Černý <xcerny37@stud.fit.vutbr.cz>
 */

#ifndef VYPE10_SCANNER_H
#define VYPE10_SCANNER_H

////
// Using flex and bison with c++ is based on example from:
// http://idlebox.net/2007/flex-bison-cpp-example/

// Flex expects the signature of yylex to be defined in the macro YY_DECL, and
// the C++ parser expects it to be declared. We can factor both as follows.

#include "parser.tab.hh"
#include "misc.h"

#ifndef YY_DECL

#define	YY_DECL						\
    vype10::Parser::token_type				\
    vype10::Scanner::lex(				\
	vype10::Parser::semantic_type* yylval,		\
	vype10::Parser::location_type* yylloc		\
    )
#endif

#ifndef __FLEX_LEXER_H
#include "FlexLexer.h"
#endif

#include "compiler.h"

namespace vype10 {

/** Scanner is a derived class to add some extra function to the scanner
 * class. Flex itself creates a class named yyFlexLexer. However we change the
 * context of the generated yylex() function to be contained within the
 * Scanner class. This is required because the yylex() defined in yyFlexLexer
 * has no parameters. */
class Scanner : public yyFlexLexer
{
public:
    /** Create a new scanner object. The streams arg_yyin and arg_yyout default
     * to cin and cout, but that assignment is only made when initializing in
     * yylex(). */
    Scanner(std::istream* arg_yyin = 0,
	    std::ostream* arg_yyout = 0);

    /** Parent - used for freeing resources during lexical error. */
    Compiler *parent;

    /** Required for virtual functions */
    virtual ~Scanner();

    /** This is the main lexing function. It is generated by flex according to
     * the macro declaration YY_DECL above. The generated bison parser then
     * calls this virtual function to fetch new tokens. */
    virtual Parser::token_type lex(
	Parser::semantic_type* yylval,
	Parser::location_type* yylloc
	);

    /** Enable debug output (via arg_yyout) if compiled into the scanner. */
    void set_debug(bool b);

    /** Prints error message, calls parent->cleanup() and then exit. */
    void lexicalError(const std::string &msg, const Parser::location_type* yylocationp);

};

} // namespace vype10

#endif // VYPE10_SCANNER_H
