
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
#line 4 "parser.yy"
 /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.h"



/* Line 311 of lalr1.cc  */
#line 53 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 102 "parser.yy"


#include "compiler.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex compiler.lexer->lex



/* Line 317 of lalr1.cc  */
#line 76 "parser.tab.cc"

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
#line 145 "parser.tab.cc"
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
#line 40 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &compiler.streamname;
}

/* Line 553 of lalr1.cc  */
#line 329 "parser.tab.cc"

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
	  case 6:

/* Line 678 of lalr1.cc  */
#line 128 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->intVal = (yysemantic_stack_[(1) - (1)].integerVal);
														(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_INT, val);
													}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 133 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->charVal = (yysemantic_stack_[(1) - (1)].charVal);
														(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_CHAR, val);
													}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 138 "parser.yy"
    {
														vype10::SymbolTable::Value *val = new vype10::SymbolTable::Value();
														val->stringVal = (yysemantic_stack_[(1) - (1)].stringVal);
														(yyval.keyString) = compiler.symbolTable->installConstant(vype10::SYM_STRING, val);
													}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 179 "parser.yy"
    { compiler.symbolTable->installSymbol((yysemantic_stack_[(3) - (2)].namesVector), (yysemantic_stack_[(3) - (1)].symbolType)); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 183 "parser.yy"
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

  case 41:

/* Line 678 of lalr1.cc  */
#line 195 "parser.yy"
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

  case 42:

/* Line 678 of lalr1.cc  */
#line 209 "parser.yy"
    { (yyval.functionType) = vype10::FUN_VOID; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 210 "parser.yy"
    { (yyval.functionType) = vype10::FUN_CHAR; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 211 "parser.yy"
    { (yyval.functionType) = vype10::FUN_SHORT; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 212 "parser.yy"
    { (yyval.functionType) = vype10::FUN_INT; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 213 "parser.yy"
    { (yyval.functionType) = vype10::FUN_STRING; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 217 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_CHAR; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 218 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_SHORT; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 219 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_INT; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 220 "parser.yy"
    { (yyval.symbolType) = vype10::SYM_STRING; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 224 "parser.yy"
    {
									(yyval.typesVector) = new std::vector<SymbolType>();
									// no check needed
									(yyval.typesVector)->push_back((yysemantic_stack_[(1) - (1)].symbolType));
								}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 229 "parser.yy"
    {
									// no check needed
									(yyval.typesVector)->push_back((yysemantic_stack_[(3) - (3)].symbolType)); 
								}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 236 "parser.yy"
    {
									(yyval.typesVector) = new std::vector<SymbolType>();
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(2) - (2)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(2) - (2)].idName) + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									compiler.symbolTable->installSymbol((yysemantic_stack_[(2) - (2)].idName), (yysemantic_stack_[(2) - (1)].symbolType), false);
									(yyval.typesVector)->push_back((yysemantic_stack_[(2) - (1)].symbolType));
								}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 246 "parser.yy"
    {
									if(compiler.symbolTable->getFunction((yysemantic_stack_[(4) - (4)].idName)) != (SymbolTable::FunctionRecord*) NULL) {
										compiler.error(yylloc, "Identifier '" + *(yysemantic_stack_[(4) - (4)].idName) + "' can't have same name as defined function.", RET_ERR_SEMANTICAL);
										YYERROR;
									}
									// install symbol to the next scope
									compiler.symbolTable->installSymbol((yysemantic_stack_[(4) - (4)].idName), (yysemantic_stack_[(4) - (3)].symbolType), false);
									(yyval.typesVector)->push_back((yysemantic_stack_[(4) - (3)].symbolType)); 
								}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 331 "parser.yy"
    {
										std::string *key;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(5) - (2)].idName), (yysemantic_stack_[(5) - (1)].functionType), (std::vector<SymbolType>*) NULL, true);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *(yysemantic_stack_[(5) - (2)].idName) + "' already defined.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 339 "parser.yy"
    {
										std::string *key;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(5) - (2)].idName), (yysemantic_stack_[(5) - (1)].functionType), (yysemantic_stack_[(5) - (4)].typesVector), true);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *(yysemantic_stack_[(5) - (2)].idName) + "' already defined.", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 354 "parser.yy"
    {
										std::string *key;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(6) - (2)].idName), (yysemantic_stack_[(6) - (1)].functionType), (std::vector<SymbolType>*) NULL, false);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *(yysemantic_stack_[(6) - (2)].idName) + "' already defined (or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 362 "parser.yy"
    {
										std::string *key;
										key = compiler.symbolTable->installFunction((yysemantic_stack_[(6) - (2)].idName), (yysemantic_stack_[(6) - (1)].functionType), (yysemantic_stack_[(6) - (4)].typesVector), false);
										if(key == (std::string*) NULL) {
											compiler.error(yylloc, "Function with name '" + *(yysemantic_stack_[(6) - (2)].idName) + "' already defined (or declared).", RET_ERR_SEMANTICAL);
											YYERROR;
										}
									}
    break;



/* Line 678 of lalr1.cc  */
#line 694 "parser.tab.cc"
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
         0,   -43,   -43,   -43,   -43,   -43,     2,     5,   -43,   -19,
     -43,   -43,     1,   -43,   -43,    58,   -43,    69,   -43,   -43,
      52,   -43,    31,    34,    49,    59,    60,    90,   -43,   -43,
     -43,   -43,    93,   102,    50,    68,   147,   285,   312,   312,
     -43,   -43,    97,   -43,   456,   -43,   142,   -43,   -43,   166,
     117,   -43,   264,   -43,   264,   -43,   -43,   104,   144,   -34,
      56,   312,   196,   312,   312,   118,   119,   135,   136,   312,
     312,   312,   -43,   -43,    73,   -43,   309,   358,   137,   -43,
     -43,   -43,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   -43,   -37,   -43,
     -43,   -43,   -43,   215,   163,   -43,   112,   -43,    74,   134,
      74,   -43,   456,   -43,    99,   456,   336,   100,   -43,   -43,
     -43,   -43,   438,   378,   398,   -43,   -43,   312,   470,   218,
     482,   493,     4,     4,    75,    75,    75,    75,    -9,    -9,
     -43,   -43,   -43,   180,   -43,   -43,   -43,   264,   -43,   -43,
     -43,   186,   312,   -43,   -43,   -43,   312,   -43,   -43,   -43,
     -43,   -43,   -43,   456,   418,   -43
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,    43,    44,    45,    42,    46,     0,     0,    79,     0,
      82,    81,     0,     1,    80,     0,    85,     0,     7,     8,
       9,     6,     0,     0,     0,     0,     0,     0,    47,    48,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    60,     0,    19,     3,    66,     0,    64,    55,     0,
       0,    56,     0,    57,     0,    58,    59,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     9,    77,     0,     0,     0,    35,
      36,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,    61,
      65,    62,    67,     0,     0,    74,    83,    53,     0,     0,
       0,    84,     2,    10,     0,     4,     0,     0,    14,    15,
      16,    17,     0,     0,     0,    78,    37,     0,    30,    29,
      24,    25,    32,    31,    26,    27,    34,    33,    20,    21,
      22,    23,    28,     0,    39,    63,    71,     0,    86,    52,
      87,     0,     0,    11,    18,    12,     0,    70,    73,    38,
      41,    72,    54,     5,     0,    13
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -43,   -43,   129,   -43,   -36,   148,   -43,   -43,   -13,   -43,
     -43,   -42,   185,   149,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   204,   -43,   -43,   -43
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,    42,   114,    43,    44,    45,    98,     6,    46,    59,
      60,    47,    48,    49,    50,    51,    52,   147,    53,    54,
      55,    56,     7,     8,     9,    10,    11
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        76,    77,    79,    80,    58,    13,   143,   100,    12,   108,
     104,   109,   105,   144,     1,     2,     3,     4,     5,     1,
       2,     3,     4,     5,    78,   112,   115,   116,   115,    94,
      95,    96,    15,   122,   123,   124,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    17,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   100,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    64,    31,    32,    65,    33,
      34,    35,    36,    28,    29,    30,    57,    31,    28,    29,
      30,   159,    31,    66,    61,   149,    62,   151,    63,   110,
      72,   111,    37,    67,    68,   161,    38,    39,    40,    15,
      41,    92,    93,    94,    95,    96,   163,    62,    73,    63,
     164,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    69,    31,    32,    70,    33,    34,
      35,    36,   152,   152,   153,   155,    71,    81,    97,   106,
     107,    18,    19,    74,    21,    22,    23,    24,    25,    26,
      27,    37,   148,   118,   119,    38,    39,    40,    15,   101,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     120,   121,   127,   146,   150,    32,   160,    33,    34,    35,
      36,    37,   162,   117,    16,    38,    39,    75,   102,   103,
      18,    19,    74,    21,    22,    23,    24,    25,    26,    27,
      37,    14,     0,     0,    38,    39,    40,    15,    99,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,    32,     0,    33,    34,    35,    36,
      37,   113,     0,     0,    38,    39,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    37,
       0,     0,     0,    38,    39,    40,    15,   145,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,    32,     0,    33,    34,    35,    36,    18,
      19,    74,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,     0,     0,     0,     0,    37,     0,
       0,     0,    38,    39,    40,    15,    18,    19,    74,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,    37,
       0,     0,     0,    38,    39,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    37,     0,     0,   125,
      38,    39,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,   154,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,   126,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,   157,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,   158,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,   165,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,   156,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        36,    37,    38,    39,    17,     0,    43,    49,     6,    43,
      52,    45,    54,    50,    14,    15,    16,    17,    18,    14,
      15,    16,    17,    18,    37,    61,    62,    63,    64,    38,
      39,    40,    51,    69,    70,    71,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    44,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   103,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    44,    18,    19,    44,    21,
      22,    23,    24,    14,    15,    16,    17,    18,    14,    15,
      16,   127,    18,    44,    42,   108,    44,   110,    46,    43,
      50,    45,    44,    44,    44,   147,    48,    49,    50,    51,
      52,    36,    37,    38,    39,    40,   152,    44,    50,    46,
     156,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    44,    18,    19,    44,    21,    22,
      23,    24,    43,    43,    45,    45,    44,    50,     6,    45,
       6,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    44,    50,    45,    45,    48,    49,    50,    51,    52,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      45,    45,    45,    20,    50,    19,     6,    21,    22,    23,
      24,    44,     6,    64,     9,    48,    49,    50,    50,    50,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      44,     7,    -1,    -1,    48,    49,    50,    51,    52,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      44,    45,    -1,    -1,    48,    49,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    44,
      -1,    -1,    -1,    48,    49,    50,    51,    52,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    49,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    50,
      48,    49,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    14,    15,    16,    17,    18,    60,    75,    76,    77,
      78,    79,     6,     0,    76,    51,    65,    44,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    18,    19,    21,    22,    23,    24,    44,    48,    49,
      50,    52,    54,    56,    57,    58,    61,    64,    65,    66,
      67,    68,    69,    71,    72,    73,    74,    17,    61,    62,
      63,    42,    44,    46,    44,    44,    44,    44,    44,    44,
      44,    44,    50,    50,     6,    50,    57,    57,    61,    57,
      57,    50,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     6,    59,    52,
      64,    52,    58,    66,    64,    64,    45,     6,    43,    45,
      43,    45,    57,    45,    55,    57,    57,    55,    45,    45,
      45,    45,    57,    57,    57,    50,    45,    45,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    43,    50,    52,    20,    70,    50,    61,
      50,    61,    43,    45,    47,    45,    43,    45,    45,    57,
       6,    64,     6,    57,    57,    45
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
      37,   287,    61,    44,    40,    41,    91,    93,    33,   126,
      59,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      59,    59,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    72,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    79,    79
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     3,     1,     1,     3,     1,     1,     1,     1,
       3,     4,     4,     6,     3,     3,     3,     3,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     4,     1,     1,     1,     1,     1,
       2,     3,     3,     4,     1,     2,     1,     2,     1,     2,
       4,     1,     4,     4,     2,     2,     2,     2,     3,     1,
       2,     1,     1,     5,     5,     2,     6,     6
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
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_OP", "'='", "','", "'('",
  "')'", "'['", "']'", "'!'", "'~'", "';'", "'{'", "'}'", "$accept",
  "assignment_expression", "argument_expression_list", "constant",
  "expression", "declaration", "declarator_list", "function_type",
  "type_specifier", "parameter_types_list", "parameter_definition_list",
  "statement", "compound_statement", "statement_list", "declaration_list",
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
        75,     0,    -1,     6,    42,    57,    -1,    57,    -1,    57,
      -1,    55,    43,    57,    -1,     7,    -1,     4,    -1,     5,
      -1,     6,    -1,     6,    44,    45,    -1,     6,    44,    55,
      45,    -1,     8,    44,    55,    45,    -1,    13,    44,    57,
      43,    57,    45,    -1,     9,    44,    45,    -1,    10,    44,
      45,    -1,    11,    44,    45,    -1,    12,    44,    45,    -1,
       6,    46,    57,    47,    -1,    56,    -1,    57,    36,    57,
      -1,    57,    37,    57,    -1,    57,    38,    57,    -1,    57,
      39,    57,    -1,    57,    28,    57,    -1,    57,    29,    57,
      -1,    57,    32,    57,    -1,    57,    33,    57,    -1,    57,
      40,    57,    -1,    57,    27,    57,    -1,    57,    26,    57,
      -1,    57,    31,    57,    -1,    57,    30,    57,    -1,    57,
      35,    57,    -1,    57,    34,    57,    -1,    48,    57,    -1,
      49,    57,    -1,    44,    57,    45,    -1,    44,    61,    45,
      57,    -1,    61,    59,    50,    -1,     6,    -1,    59,    43,
       6,    -1,    17,    -1,    14,    -1,    15,    -1,    16,    -1,
      18,    -1,    14,    -1,    15,    -1,    16,    -1,    18,    -1,
      61,    -1,    62,    43,    61,    -1,    61,     6,    -1,    63,
      43,    61,     6,    -1,    65,    -1,    68,    -1,    71,    -1,
      73,    -1,    74,    -1,    51,    52,    -1,    51,    66,    52,
      -1,    51,    67,    52,    -1,    51,    67,    66,    52,    -1,
      64,    -1,    66,    64,    -1,    58,    -1,    67,    58,    -1,
      50,    -1,    54,    50,    -1,    19,    44,    57,    45,    -1,
      20,    -1,    69,    64,    70,    64,    -1,    21,    44,    57,
      45,    -1,    72,    64,    -1,    22,    50,    -1,    23,    50,
      -1,    24,    50,    -1,    24,    57,    50,    -1,    76,    -1,
      75,    76,    -1,    79,    -1,    78,    -1,    60,     6,    44,
      17,    45,    -1,    60,     6,    44,    63,    45,    -1,    77,
      65,    -1,    60,     6,    44,    17,    45,    50,    -1,    60,
       6,    44,    62,    45,    50,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     7,     9,    11,    15,    17,    19,    21,
      23,    27,    32,    37,    44,    48,    52,    56,    60,    65,
      67,    71,    75,    79,    83,    87,    91,    95,    99,   103,
     107,   111,   115,   119,   123,   127,   130,   133,   137,   142,
     146,   148,   152,   154,   156,   158,   160,   162,   164,   166,
     168,   170,   172,   176,   179,   184,   186,   188,   190,   192,
     194,   197,   201,   205,   210,   212,   215,   217,   220,   222,
     225,   230,   232,   237,   242,   245,   248,   251,   254,   258,
     260,   263,   265,   267,   273,   279,   282,   289
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   118,   118,   119,   123,   124,   128,   133,   138,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   179,
     183,   195,   209,   210,   211,   212,   213,   217,   218,   219,
     220,   224,   229,   236,   246,   258,   259,   260,   261,   262,
     266,   267,   268,   269,   273,   274,   278,   279,   283,   284,
     290,   295,   299,   304,   308,   312,   313,   314,   315,   319,
     320,   324,   325,   331,   339,   350,   354,   362
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
       2,     2,     2,    48,     2,     2,     2,    40,    29,     2,
      44,    45,    38,    36,    43,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      32,    42,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    28,    52,    49,     2,     2,     2,
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
      25,    26,    27,    30,    31,    34,    35,    41
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 533;
  const int Parser::yynnts_ = 27;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 13;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 53;

  const unsigned int Parser::yyuser_token_number_max_ = 287;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // vype10

/* Line 1054 of lalr1.cc  */
#line 1342 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 372 "parser.yy"
 /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m, RET_ERR_SYNTACTICAL);
}

