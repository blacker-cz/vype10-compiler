/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>

#include "scanner.h"
#include "parser.tab.hh"

/* import the parser's token type into a local typedef */
typedef vype10::Parser::token token;
typedef vype10::Parser::token_type token_type;

std::string *stringBuilder; 

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

#define YY_EXIT_FAILURE 1

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ExampleFlexLexer" 
%option prefix="VYPe10"*/

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%x str

letter		[_a-zA-Z]
letnum		[_a-zA-Z0-9]
identifier	{letter}{letnum}*
digit		[0-9]
number		{digit}+
newline		\n
whitespace	[ \t]+

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}
"//"			{ char c;
				  while ((c = yyinput()) != '\n')
				    if (c == EOF) return token::END;
				  yyunput(c, yy_c_buf_p);
				}
"/*"            { char c;
                  bool done = false;
                  do {
                    while ((c = yyinput()) != '*')
                      if (c == EOF) return token::ERROR_COMMENT;
                    while ((c = yyinput()) == '*');
                    if (c == '/') done = true;
                  } while (!done);
                }

"int"           {return token::INT;}
"short"         {return token::SHORT;}
"char"          {return token::CHAR;}
"void"          {return token::VOID;}
"string"        {return token::STRING;}
"if"            {return token::IF;}
"else"          {return token::ELSE;}
"while"         {return token::WHILE;}
"continue"      {return token::CONTINUE;}
"break"         {return token::BREAK;}
"return"        {return token::RETURN;}
"<="            {return token::LE_OP;}
">="            {return token::GE_OP;}
"=="            {return token::EQ_OP;}
"!="            {return token::NE_OP;}
"&&"            {return token::AND_OP;}
"||"            {return token::OR_OP;}
"}"		{return (token_type)'}'; }
"{"		{return (token_type)'{'; }
";"		{return (token_type)';'; }
","		{return (token_type)','; }
":"		{return (token_type)':'; }
"="		{return (token_type)'='; }
"("		{return (token_type)'('; }
")"		{return (token_type)')'; }
"["		{return (token_type)'['; }
"]"		{return (token_type)']'; }
"."		{return (token_type)'.'; }
"&"		{return (token_type)'&'; }
"!"		{return (token_type)'!'; }
"~"		{return (token_type)'~'; }
"-"		{return (token_type)'-'; }
"+"		{return (token_type)'+'; }
"*"		{return (token_type)'*'; }
"/"		{return (token_type)'/'; }
"%"		{return (token_type)'%'; }
"<"		{return (token_type)'<'; }
">"		{return (token_type)'>'; }
"|"		{return (token_type)'|'; }
"?"		{return (token_type)'?'; }

{identifier}    {
	yylval->idName = new std::string(yytext, yyleng);
	return token::ID;
}

{number}        {
	yylval->integerVal = atoi(yytext);
	return token::CONSTANT;
}

{newline}	{
	yylloc->lines(yyleng); yylloc->step();
}

 /*
	Character literal definition
 */

\'\\n\'	{
		yylval->charVal = '\n';
		return token::CHAR_LITERAL;
	} 
\'\\t\'	{
		yylval->charVal = '\t';
		return token::CHAR_LITERAL;
	} 
\'\\\\\'	{
		yylval->charVal = '\\';
		return token::CHAR_LITERAL;
	} 
\'\\\"\'	{
		yylval->charVal = '"';
		return token::CHAR_LITERAL;
	} 

\'\\\'\'	{
		yylval->charVal = '\'';
		return token::CHAR_LITERAL;
	} 

\'[^\\]\' {
		yylval->charVal = *(yytext+1);
		return token::CHAR_LITERAL;
}

 /*
	Invalid character literal
 */

\' {
	return token::ERROR_CHAR;
}

 /*
	String literal definition
 */
   
\"      stringBuilder = new std::string(); BEGIN(str);
     
<str>\"        { /* saw closing quote - all done */
        BEGIN(INITIAL);
        yylval->stringVal = stringBuilder;
        stringBuilder = NULL;
        return token::STRING_LITERAL;
        }
     
<str>\n        {
        /* error - unterminated string constant */
        LexerError("unterminated string constant");
        }
     
<str>\\n  	stringBuilder->append("\n");
<str>\\t  	stringBuilder->append("\t");
<str>\\\\  	stringBuilder->append("\\");
<str>\\\"  	stringBuilder->append("\"");
<str>\\\'  	stringBuilder->append("'");
     
<str>[^\\\n\"]+        {
		stringBuilder->append(yytext);
      }

 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

%% /*** Additional Code ***/


namespace vype10 {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : yyFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}


#ifdef yylex
#undef yylex
#endif

int yyFlexLexer::yylex()
{
    std::cerr << "in yyFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int yyFlexLexer::yywrap()
{
    return 1;
}
