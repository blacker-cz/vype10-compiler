
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   vype10lex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 8 "parser.yy"
 /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "symbolTable.h"



/* Line 311 of lalr1.cc  */
#line 54 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 105 "parser.yy"


#include "compiler.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex compiler.lexer->lex



/* Line 317 of lalr1.cc  */
#line 77 "parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace vype10 {

/* Line 380 of lalr1.cc  */
#line 146 "parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Compiler& compiler_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      compiler (compiler_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 44 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &compiler.streamname;
}

/* Line 553 of lalr1.cc  */
#line 330 "parser.tab.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 121 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].idName), true);
								if(first == (SymbolTable::SymbolRecord*) NULL) {
									compiler.error(yylloc, "Undefined identifier '" + *(yysemantic_stack_[(3) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {
									compiler.intermediateCode->add(vype10::IntermediateCode::ASSIGN, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, compiler.symbolTable->getSymbolKey((yysemantic_stack_[(3) - (1)].idName), true));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									compiler.intermediateCode->add(vype10::IntermediateCode::ASSIGN, pom, (std::string*) NULL, compiler.symbolTable->getSymbolKey((yysemantic_stack_[(3) - (1)].idName), true));
								} else {
									compiler.error(yylloc, "Mismatching types in assignment.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 143 "parser.yy"
    {
									(yyval.typesVector) = new std::vector<SymbolType>();

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(1) - (1)].keyString), true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PUSH, (yysemantic_stack_[(1) - (1)].keyString), (std::string*) NULL, (std::string*) NULL);

									(yyval.typesVector)->push_back(sym->type);
								}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 156 "parser.yy"
    {

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PUSH, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, (std::string*) NULL);

									(yyval.typesVector)->push_back(sym->type);
								}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 171 "parser.yy"
    {
									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(1) - (1)].keyString), true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PRINT, (yysemantic_stack_[(1) - (1)].keyString), (std::string*) NULL, (std::string*) NULL);
									
								}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 181 "parser.yy"
    {

									SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
									if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
										compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
										YYERROR;
									}
									
									compiler.intermediateCode->add(vype10::IntermediateCode::PRINT, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, (std::string*) NULL);
								}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 194 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->intVal = (yysemantic_stack_[(1) - (1)].integerVal);
														if((yysemantic_stack_[(1) - (1)].integerVal) >= SHRT_MIN && (yysemantic_stack_[(1) - (1)].integerVal) <= SHRT_MAX) {
															(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_SHORT, val);
														} else {
															(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_INT, val);
														}
													}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 203 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->charVal = (yysemantic_stack_[(1) - (1)].charVal);
														(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_CHAR, val);
													}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 208 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->stringVal = (yysemantic_stack_[(1) - (1)].stringVal);
														(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_STRING, val);
													}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 216 "parser.yy"
    {
														(yyval.keyString) = compiler.symbolTable->getSymbolKey((yysemantic_stack_[(1) - (1)].idName), true);
														if((yyval.keyString) == (std::string*) NULL) {
															compiler.error(yylloc, "Undefined identifier '" + *(yysemantic_stack_[(1) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
													}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 223 "parser.yy"
    {
														SymbolTable::FunctionRecord *fun = compiler.symbolTable->getFunction((yysemantic_stack_[(3) - (1)].idName));
														if(fun == (SymbolTable::FunctionRecord*) NULL) {
															compiler.error(yylloc, "Call of undefined/undeclared function '" + *(yysemantic_stack_[(3) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->paramsType.size() != 0) {
															compiler.error(yylloc, "Function '" + *(yysemantic_stack_[(3) - (1)].idName) + "' expect " + (char) ('0' + (int)fun->paramsType.size()) + " params, none given.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->type != vype10::FUN_VOID) {
															(yyval.keyString) = compiler.symbolTable->installSymbol((vype10::SymbolType) fun->type);
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, (yysemantic_stack_[(3) - (1)].idName), (std::string*) NULL, (yyval.keyString));
														} else {
															(yyval.keyString) = (std::string*) NULL;
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, (yysemantic_stack_[(3) - (1)].idName), (std::string*) NULL, (std::string*) NULL);
														}
													}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 241 "parser.yy"
    {
														SymbolTable::FunctionRecord *fun = compiler.symbolTable->getFunction((yysemantic_stack_[(4) - (1)].idName));
														if(fun == (SymbolTable::FunctionRecord*) NULL) {
															compiler.error(yylloc, "Call of undefined/undeclared function '" + *(yysemantic_stack_[(4) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->paramsType != *(yysemantic_stack_[(4) - (3)].typesVector)) {
															compiler.error(yylloc, "Invalid arguments passed to function '" + *(yysemantic_stack_[(4) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(fun->type != vype10::FUN_VOID) {
															(yyval.keyString) = compiler.symbolTable->installSymbol((vype10::SymbolType) fun->type);
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, (yysemantic_stack_[(4) - (1)].idName), (std::string*) NULL, (yyval.keyString));
														} else {
															(yyval.keyString) = (std::string*) NULL;
															compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_CALL, (yysemantic_stack_[(4) - (1)].idName), (std::string*) NULL, (std::string*) NULL);
														}
													}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 259 "parser.yy"
    { (yyval.keyString) = (std::string*) NULL; }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 260 "parser.yy"
    {
														SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(6) - (3)].keyString), true);
														if(first->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "First parameter must be of type string.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(6) - (5)].keyString), true);
														if(second->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "Second parameter must be of type string.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
														compiler.intermediateCode->add(vype10::IntermediateCode::STRCAT, (yysemantic_stack_[(6) - (3)].keyString), (yysemantic_stack_[(6) - (5)].keyString), (yyval.keyString));
													}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 274 "parser.yy"
    {
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_CHAR);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_CHAR, (std::string*)NULL, (std::string*)NULL, (yyval.keyString));
													}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 278 "parser.yy"
    {
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_SHORT, (std::string*)NULL, (std::string*)NULL, (yyval.keyString));
													}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 282 "parser.yy"
    {
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_INT, (std::string*)NULL, (std::string*)NULL, (yyval.keyString));
													}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 286 "parser.yy"
    {
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
														compiler.intermediateCode->add(vype10::IntermediateCode::READ_STRING, (std::string*)NULL, (std::string*)NULL, (yyval.keyString));
													}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 290 "parser.yy"
    {
														SymbolTable::SymbolRecord *id = compiler.symbolTable->getSymbol((yysemantic_stack_[(4) - (1)].idName), true);
														if(id == (SymbolTable::SymbolRecord*) NULL) {
															compiler.error(yylloc, "Undefined identifier '" + *(yysemantic_stack_[(4) - (1)].idName) + "'.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														if(id->type != vype10::SYM_STRING) {
															compiler.error(yylloc, "Only strings allow array access.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(4) - (3)].keyString), true);
														if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
															compiler.error(yylloc, "Index must be of type short or int.", RET_ERR_SEMANTICAL);
															YYERROR;
														}
														(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_CHAR);
														compiler.intermediateCode->add(vype10::IntermediateCode::INDEX, compiler.symbolTable->getSymbolKey((yysemantic_stack_[(4) - (1)].idName), true), (yysemantic_stack_[(4) - (3)].keyString), (yyval.keyString));
													}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 309 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '+' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::ADD, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
							}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 323 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '-' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::SUB, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
							}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 337 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '*' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::MUL, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
							}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 351 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
								} else {
									compiler.error(yylloc, "Invalid types in '/' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::DIV, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
							}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 365 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_OR, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 386 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_AND, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 407 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LT, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '<' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 428 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GT, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '>' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 449 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(first->type);
								} else if(first->type != second->type && ((first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) || (first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT))) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
								} else {
									compiler.error(yylloc, "Invalid types in '%' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
								
								compiler.intermediateCode->add(vype10::IntermediateCode::MOD, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
							}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 463 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::AND, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '&&' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 484 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type && (first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT)) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::OR, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '||' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 505 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::EQ, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '==' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 526 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NE, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '!=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 547 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::LE, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '<=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 568 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (1)].keyString), true);
								SymbolTable::SymbolRecord *second = compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].keyString), true);
								if(first->type == second->type) {	// ok
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, (yysemantic_stack_[(3) - (1)].keyString), (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else if(first->type == vype10::SYM_INT && second->type == vype10::SYM_SHORT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (3)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, (yysemantic_stack_[(3) - (1)].keyString), pom, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT && second->type == vype10::SYM_INT) {
									std::string* pom = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(3) - (1)].keyString), (std::string*) NULL, pom);
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::GE, pom, (yysemantic_stack_[(3) - (3)].keyString), (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid types in '>=' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 589 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(2) - (2)].keyString), true);
								if(first->type == vype10::SYM_INT || first->type == vype10::SYM_SHORT) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::NOT, (yysemantic_stack_[(2) - (2)].keyString), (std::string*) NULL, (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid type in '!' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 599 "parser.yy"
    {
								SymbolTable::SymbolRecord *first = compiler.symbolTable->getSymbol((yysemantic_stack_[(2) - (2)].keyString), true);
								if(first->type == vype10::SYM_INT) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_NOT, (yysemantic_stack_[(2) - (2)].keyString), (std::string*) NULL, (yyval.keyString));
								} else if(first->type == vype10::SYM_SHORT) {
									(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
									compiler.intermediateCode->add(vype10::IntermediateCode::BIN_NOT, (yysemantic_stack_[(2) - (2)].keyString), (std::string*) NULL, (yyval.keyString));
								} else {
									compiler.error(yylloc, "Invalid type in '~' expression.", RET_ERR_SEMANTICAL);
									YYERROR;
								}
							}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 612 "parser.yy"
    { (yyval.keyString) = (yysemantic_stack_[(3) - (2)].keyString); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 613 "parser.yy"
    {
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(4) - (4)].keyString), true);
										if(sym == (SymbolTable::SymbolRecord*) NULL) {	// this shouldn't happen
											compiler.error(yylloc, "Lost expression result.", RET_ERR_INTERNAL);
											YYERROR;
										}
										
										if(sym->type == (yysemantic_stack_[(4) - (2)].symbolType)) {	// same type -> do nothing
											(yyval.keyString) = (yysemantic_stack_[(4) - (4)].keyString);
										} else if(sym->type == vype10::SYM_CHAR && (yysemantic_stack_[(4) - (2)].symbolType) == vype10::SYM_STRING) {	// char -> string
											(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_STRING);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(4) - (4)].keyString), (std::string*) NULL, (yyval.keyString));
										} else if(sym->type == vype10::SYM_CHAR && (yysemantic_stack_[(4) - (2)].symbolType) == vype10::SYM_SHORT) {	// char -> short
											(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_SHORT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(4) - (4)].keyString), (std::string*) NULL, (yyval.keyString));
										} else if(sym->type == vype10::SYM_CHAR && (yysemantic_stack_[(4) - (2)].symbolType) == vype10::SYM_INT) {		// char -> int
											(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(4) - (4)].keyString), (std::string*) NULL, (yyval.keyString));
										} else if(sym->type == vype10::SYM_SHORT && (yysemantic_stack_[(4) - (2)].symbolType) == vype10::SYM_INT) {	// short -> int
											(yyval.keyString) = compiler.symbolTable->installSymbol(vype10::SYM_INT);
											compiler.intermediateCode->add(vype10::IntermediateCode::CAST, (yysemantic_stack_[(4) - (4)].keyString), (std::string*) NULL, (yyval.keyString));
										} else {
											compiler.error(yylloc, "Invalid cast.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
 									}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 642 "parser.yy"
    { compiler.symbolTable->installSymbol((yysemantic_stack_[(3) - (2)].namesVector), (yysemantic_stack_[(3) - (1)].symbolType)); }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 646 "parser.yy"
    {
									(yyval.namesVector) = new std::vector<std::string*>();
									if(compiler.symbolTable->getSymbol((yysemantic_stack_[(1) - (1)].idName)) != (SymbolTable::SymbolRecord*) NULL || compiler.symbolTable->getFunction((yysemantic_stack_[(1) - (1)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier with name '" + *(yysemantic_stack_[(1) - (1)].idName) + "' already defined.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(1) - (1)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(1) - (1)].idName) + "' can't have same name as defined/declared function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									(yyval.namesVector)->push_back((yysemantic_stack_[(1) - (1)].idName));
								}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 658 "parser.yy"
    {
									if(compiler.symbolTable->getSymbol((yysemantic_stack_[(3) - (3)].idName)) != (SymbolTable::SymbolRecord*) NULL) {
										compiler.error(yylloc, "Identifier with name '" + *(yysemantic_stack_[(3) - (3)].idName) + "' already defined.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(3) - (3)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(3) - (3)].idName) + "' can't have same name as defined/declared function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									(yyval.namesVector)->push_back((yysemantic_stack_[(3) - (3)].idName)); 
								}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 672 "parser.yy"
    { (yyval.functionType) = vype10::FUN_VOID; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 673 "parser.yy"
    { (yyval.functionType) = vype10::FUN_CHAR; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 674 "parser.yy"
    { (yyval.functionType) = vype10::FUN_SHORT; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 675 "parser.yy"
    { (yyval.functionType) = vype10::FUN_INT; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 676 "parser.yy"
    { (yyval.functionType) = vype10::FUN_STRING; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 680 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_CHAR; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 681 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_SHORT; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 682 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_INT; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 683 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_STRING; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 687 "parser.yy"
    {
									(yyval.typesVector) = new std::vector<SymbolType>();
									// no check needed
									(yyval.typesVector)->push_back((yysemantic_stack_[(1) - (1)].symbolType));
								}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 692 "parser.yy"
    {
									// no check needed
									(yyval.typesVector)->push_back((yysemantic_stack_[(3) - (3)].symbolType)); 
								}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 699 "parser.yy"
    {
									(yyval.namesVector) = new std::vector<std::string*>();
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(2) - (2)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(2) - (2)].idName) + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									std::string* sym = compiler.symbolTable->installSymbol((yysemantic_stack_[(2) - (2)].idName), (yysemantic_stack_[(2) - (1)].symbolType), false);
									(yyval.namesVector)->push_back(sym);
								}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 709 "parser.yy"
    {
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(4) - (4)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(4) - (4)].idName) + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									std::string* sym = compiler.symbolTable->installSymbol((yysemantic_stack_[(4) - (4)].idName), (yysemantic_stack_[(4) - (3)].symbolType), false);
									(yyval.namesVector)->push_back(sym); 
								}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 753 "parser.yy"
    {
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(4) - (3)].keyString), true);
										if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
											compiler.error(yylloc, "Expression must be of type short or int.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
										compiler.intermediateCode->add(vype10::IntermediateCode::IF, compiler.symbolTable->getSymbolKey((yysemantic_stack_[(4) - (3)].keyString), true), (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 765 "parser.yy"
    {
										compiler.intermediateCode->add(vype10::IntermediateCode::ELSE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 771 "parser.yy"
    {
										compiler.intermediateCode->add(vype10::IntermediateCode::ENDIF, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 778 "parser.yy"
    {
										SymbolTable::SymbolRecord *sym = compiler.symbolTable->getSymbol((yysemantic_stack_[(4) - (3)].keyString), true);
										if(sym->type != vype10::SYM_SHORT && sym->type != vype10::SYM_INT) {
											compiler.error(yylloc, "Expression must be of type short or int.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
										compiler.intermediateCode->add(vype10::IntermediateCode::WHILE, compiler.symbolTable->getSymbolKey((yysemantic_stack_[(4) - (3)].keyString), true), (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 790 "parser.yy"
    {
									compiler.intermediateCode->add(vype10::IntermediateCode::ENDWHILE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 796 "parser.yy"
    {
									compiler.intermediateCode->add(vype10::IntermediateCode::CONTINUE, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 799 "parser.yy"
    {
									compiler.intermediateCode->add(vype10::IntermediateCode::BREAK, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 802 "parser.yy"
    {
									compiler.intermediateCode->add(vype10::IntermediateCode::RETURN, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
								}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 805 "parser.yy"
    {
									compiler.intermediateCode->add(vype10::IntermediateCode::RETURN, (yysemantic_stack_[(3) - (2)].keyString), (std::string*) NULL,  (std::string*) NULL);
								}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 823 "parser.yy"
    {
										std::string *key;
										std::string error;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(5) - (2)].idName), (yysemantic_stack_[(5) - (1)].functionType), (std::vector<SymbolType>*) NULL, true, error);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, error, RET_ERR_SEMANTICAL);
											YYERROR;
										}

										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_DEF, key, (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 834 "parser.yy"
    {
										std::string *key;
										std::string error;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(5) - (2)].idName), (yysemantic_stack_[(5) - (1)].functionType), (yysemantic_stack_[(5) - (4)].namesVector), true, error);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, error, RET_ERR_SEMANTICAL);
											YYERROR;
										}

										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_DEF, key, (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 848 "parser.yy"
    {
										compiler.intermediateCode->add(vype10::IntermediateCode::FUNC_END, (std::string*) NULL, (std::string*) NULL,  (std::string*) NULL);
									}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 854 "parser.yy"
    {
										std::string *key;
										std::string error;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(6) - (2)].idName), (yysemantic_stack_[(6) - (1)].functionType), (std::vector<SymbolType>*) NULL, false, error);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, error + "(or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 863 "parser.yy"
    {
										std::string *key;
										std::string error;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(6) - (2)].idName), (yysemantic_stack_[(6) - (1)].functionType), (yysemantic_stack_[(6) - (4)].typesVector), false, error);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, error + " (or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;



/* Line 678 of lalr1.cc  */
#line 1496 "parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -43;
  const short int
  Parser::yypact_[] =
  {
         0,   -43,   -43,   -43,   -43,   -43,     2,     5,   -43,   -20,
     -43,   -43,    30,   -43,   -43,    58,   -43,    69,   -43,   -43,
      71,   -43,    33,    43,    59,    60,    67,    74,   -43,   -43,
     -43,   -43,    76,    91,    -6,    88,   149,   290,   318,   318,
     -43,   -43,    97,   -43,   469,   -43,   143,   -43,   -43,   169,
     119,   -43,   269,   -43,   269,   -43,   -43,   104,   145,   -35,
      50,   318,   199,   318,   318,   106,   117,   120,   121,   318,
     318,   318,   -43,   -43,    68,   -43,   315,   366,   137,   -43,
     -43,   -43,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   -43,   -38,   -43,
     -43,   -43,   -43,   219,   164,   -43,   114,   -43,    75,   134,
      75,   -43,   469,   -43,   100,   469,   343,   101,   469,   -43,
     -43,   -43,   -43,   450,   387,   408,   -43,   -43,   318,   223,
     482,   494,   505,     4,     4,    62,    62,    62,    62,    -9,
      -9,   -43,   -43,   -43,   180,   -43,   -43,   -43,   269,   -43,
     -43,   -43,   181,   318,   -43,   -43,   318,   -43,   318,   -43,
     -43,   -43,   -43,   -43,   -43,   469,   469,   429,   -43
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,    45,    46,    47,    44,    48,     0,     0,    81,     0,
      84,    83,     0,     1,    82,     0,    87,     0,     9,    10,
      11,     8,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    62,     0,    21,     3,    68,     0,    66,    57,     0,
       0,    58,     0,    59,     0,    60,    61,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    11,    79,     0,     0,     0,    37,
      38,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,    63,
      67,    64,    69,     0,     0,    76,    85,    55,     0,     0,
       0,    86,     2,    12,     0,     4,     0,     0,     6,    16,
      17,    18,    19,     0,     0,     0,    80,    39,     0,    32,
      31,    26,    27,    34,    33,    28,    29,    36,    35,    22,
      23,    24,    25,    30,     0,    41,    65,    73,     0,    88,
      54,    89,     0,     0,    13,    20,     0,    14,     0,    72,
      75,    40,    43,    74,    56,     5,     7,     0,    15
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -43,   -43,   -43,   -43,   -43,   -36,   139,   -43,   -43,   -13,
     -43,   -43,   -42,   186,   146,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   190,   -43,   -43,   -43
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,    42,   114,   117,    43,    44,    45,    98,     6,    46,
      59,    60,    47,    48,    49,    50,    51,    52,   148,    53,
      54,    55,    56,     7,     8,     9,    10,    11
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        76,    77,    79,    80,    58,    13,   144,   100,    12,   108,
     104,   109,   105,   145,     1,     2,     3,     4,     5,     1,
       2,     3,     4,     5,    78,   112,   115,   116,   118,    94,
      95,    96,    15,   123,   124,   125,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    72,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   100,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    17,    31,    32,    64,    33,
      34,    35,    36,    28,    29,    30,    57,    31,    65,    28,
      29,    30,   161,    31,   110,   150,   111,   152,    92,    93,
      94,    95,    96,    37,    66,    67,   163,    38,    39,    40,
      15,    41,    68,    62,    61,    63,    62,   165,    63,    69,
     166,    70,   167,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    71,    31,    32,    73,
      33,    34,    35,    36,   153,   156,   154,   157,    81,    97,
     106,   107,   119,    18,    19,    74,    21,    22,    23,    24,
      25,    26,    27,   120,    37,   149,   121,   122,    38,    39,
      40,    15,   101,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   128,   147,   151,   162,   164,    32,   102,
      33,    34,    35,    36,    37,    16,   103,    14,    38,    39,
      75,     0,     0,    18,    19,    74,    21,    22,    23,    24,
      25,    26,    27,     0,    37,     0,     0,     0,    38,    39,
      40,    15,    99,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    32,     0,
      33,    34,    35,    36,    37,   113,     0,     0,    38,    39,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    37,     0,     0,     0,    38,    39,
      40,    15,   146,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    32,     0,
      33,    34,    35,    36,    18,    19,    74,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    38,    39,
      40,    15,    18,    19,    74,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,    37,     0,     0,     0,    38,
      39,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,   126,    38,    39,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,   155,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,   127,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,   159,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,   160,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,   168,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,     0,   158,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        36,    37,    38,    39,    17,     0,    44,    49,     6,    44,
      52,    46,    54,    51,    14,    15,    16,    17,    18,    14,
      15,    16,    17,    18,    37,    61,    62,    63,    64,    38,
      39,    40,    52,    69,    70,    71,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    51,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   103,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    45,    18,    19,    45,    21,
      22,    23,    24,    14,    15,    16,    17,    18,    45,    14,
      15,    16,   128,    18,    44,   108,    46,   110,    36,    37,
      38,    39,    40,    45,    45,    45,   148,    49,    50,    51,
      52,    53,    45,    45,    43,    47,    45,   153,    47,    45,
     156,    45,   158,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    45,    18,    19,    51,
      21,    22,    23,    24,    44,    44,    46,    46,    51,     6,
      46,     6,    46,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    46,    45,    51,    46,    46,    49,    50,
      51,    52,    53,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    46,    20,    51,     6,     6,    19,    50,
      21,    22,    23,    24,    45,     9,    50,     7,    49,    50,
      51,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    24,    45,    46,    -1,    -1,    49,    50,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    24,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    50,
      51,    52,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    51,    49,    50,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    14,    15,    16,    17,    18,    62,    77,    78,    79,
      80,    81,     6,     0,    78,    52,    67,    45,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    18,    19,    21,    22,    23,    24,    45,    49,    50,
      51,    53,    55,    58,    59,    60,    63,    66,    67,    68,
      69,    70,    71,    73,    74,    75,    76,    17,    63,    64,
      65,    43,    45,    47,    45,    45,    45,    45,    45,    45,
      45,    45,    51,    51,     6,    51,    59,    59,    63,    59,
      59,    51,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     6,    61,    53,
      66,    53,    60,    68,    66,    66,    46,     6,    44,    46,
      44,    46,    59,    46,    56,    59,    59,    57,    59,    46,
      46,    46,    46,    59,    59,    59,    51,    46,    46,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    44,    51,    53,    20,    72,    51,
      63,    51,    63,    44,    46,    48,    44,    46,    44,    46,
      46,    59,     6,    66,     6,    59,    59,    59,    46
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   124,    38,
     283,   284,    60,    62,   285,   286,    43,    45,    42,    47,
      37,   287,   288,    61,    44,    40,    41,    91,    93,    33,
     126,    59,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    81,    81
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     3,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     4,     4,     6,     3,     3,     3,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       4,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     4,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     4,     1,     4,     4,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     5,     5,     2,     6,     6
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"character\"", "\"string\"", "\"identificator\"",
  "\"number constant\"", "PRINT", "READ_CHAR", "READ_SHORT", "READ_INT",
  "READ_STRING", "STRCAT", "CHAR", "SHORT", "INT", "VOID", "STRING", "IF",
  "ELSE", "WHILE", "CONTINUE", "BREAK", "RETURN", "LOW_PRIORITY", "OR_OP",
  "AND_OP", "'|'", "'&'", "NE_OP", "EQ_OP", "'<'", "'>'", "GE_OP", "LE_OP",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_OP", "HIGH_PRIORITY", "'='",
  "','", "'('", "')'", "'['", "']'", "'!'", "'~'", "';'", "'{'", "'}'",
  "$accept", "assignment_expression", "argument_expression_list",
  "print_expression_list", "constant", "expression", "declaration",
  "declarator_list", "function_type", "type_specifier",
  "parameter_types_list", "parameter_definition_list", "statement",
  "compound_statement", "statement_list", "declaration_list",
  "expression_statement", "if_statement", "else_statement",
  "selection_statement", "while_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_head", "function_definition", "function_declaration", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        77,     0,    -1,     6,    43,    59,    -1,    59,    -1,    59,
      -1,    56,    44,    59,    -1,    59,    -1,    57,    44,    59,
      -1,     7,    -1,     4,    -1,     5,    -1,     6,    -1,     6,
      45,    46,    -1,     6,    45,    56,    46,    -1,     8,    45,
      57,    46,    -1,    13,    45,    59,    44,    59,    46,    -1,
       9,    45,    46,    -1,    10,    45,    46,    -1,    11,    45,
      46,    -1,    12,    45,    46,    -1,     6,    47,    59,    48,
      -1,    58,    -1,    59,    36,    59,    -1,    59,    37,    59,
      -1,    59,    38,    59,    -1,    59,    39,    59,    -1,    59,
      28,    59,    -1,    59,    29,    59,    -1,    59,    32,    59,
      -1,    59,    33,    59,    -1,    59,    40,    59,    -1,    59,
      27,    59,    -1,    59,    26,    59,    -1,    59,    31,    59,
      -1,    59,    30,    59,    -1,    59,    35,    59,    -1,    59,
      34,    59,    -1,    49,    59,    -1,    50,    59,    -1,    45,
      59,    46,    -1,    45,    63,    46,    59,    -1,    63,    61,
      51,    -1,     6,    -1,    61,    44,     6,    -1,    17,    -1,
      14,    -1,    15,    -1,    16,    -1,    18,    -1,    14,    -1,
      15,    -1,    16,    -1,    18,    -1,    63,    -1,    64,    44,
      63,    -1,    63,     6,    -1,    65,    44,    63,     6,    -1,
      67,    -1,    70,    -1,    73,    -1,    75,    -1,    76,    -1,
      52,    53,    -1,    52,    68,    53,    -1,    52,    69,    53,
      -1,    52,    69,    68,    53,    -1,    66,    -1,    68,    66,
      -1,    60,    -1,    69,    60,    -1,    51,    -1,    55,    51,
      -1,    19,    45,    59,    46,    -1,    20,    -1,    71,    66,
      72,    66,    -1,    21,    45,    59,    46,    -1,    74,    66,
      -1,    22,    51,    -1,    23,    51,    -1,    24,    51,    -1,
      24,    59,    51,    -1,    78,    -1,    77,    78,    -1,    81,
      -1,    80,    -1,    62,     6,    45,    17,    46,    -1,    62,
       6,    45,    65,    46,    -1,    79,    67,    -1,    62,     6,
      45,    17,    46,    51,    -1,    62,     6,    45,    64,    46,
      51,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     7,     9,    11,    15,    17,    21,    23,
      25,    27,    29,    33,    38,    43,    50,    54,    58,    62,
      66,    71,    73,    77,    81,    85,    89,    93,    97,   101,
     105,   109,   113,   117,   121,   125,   129,   133,   136,   139,
     143,   148,   152,   154,   158,   160,   162,   164,   166,   168,
     170,   172,   174,   176,   178,   182,   185,   190,   192,   194,
     196,   198,   200,   203,   207,   211,   216,   218,   221,   223,
     226,   228,   231,   236,   238,   243,   248,   251,   254,   257,
     260,   264,   266,   269,   271,   273,   279,   285,   288,   295
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   121,   121,   139,   143,   156,   171,   181,   194,   203,
     208,   216,   223,   241,   259,   260,   274,   278,   282,   286,
     290,   308,   309,   323,   337,   351,   365,   386,   407,   428,
     449,   463,   484,   505,   526,   547,   568,   589,   599,   612,
     613,   642,   646,   658,   672,   673,   674,   675,   676,   680,
     681,   682,   683,   687,   692,   699,   709,   721,   722,   723,
     724,   725,   729,   730,   731,   732,   736,   737,   741,   742,
     746,   747,   753,   765,   771,   778,   790,   796,   799,   802,
     805,   811,   812,   816,   817,   823,   834,   848,   854,   863
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    40,    29,     2,
      45,    46,    38,    36,    44,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      32,    43,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    28,    53,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    30,    31,    34,    35,    41,    42
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 545;
  const int Parser::yynnts_ = 28;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 13;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 54;

  const unsigned int Parser::yyuser_token_number_max_ = 288;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // vype10

/* Line 1054 of lalr1.cc  */
#line 2148 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 874 "parser.yy"
 /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m, RET_ERR_SYNTACTICAL);
}

