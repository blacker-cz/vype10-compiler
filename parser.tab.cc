
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



/* Line 311 of lalr1.cc  */
#line 52 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 97 "parser.yy"


#include "compiler.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex compiler.lexer->lex



/* Line 317 of lalr1.cc  */
#line 75 "parser.tab.cc"

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
#line 144 "parser.tab.cc"
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
#line 39 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &compiler.streamname;
}

/* Line 553 of lalr1.cc  */
#line 328 "parser.tab.cc"

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
#line 123 "parser.yy"
    { std::cerr << "Identifier: " << *(yysemantic_stack_[(1) - (1)].idName) << std::endl; }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 124 "parser.yy"
    { std::cerr << "Int constant: " << (yysemantic_stack_[(1) - (1)].integerVal) << std::endl; }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 125 "parser.yy"
    { std::cerr << "Character literal: " << (yysemantic_stack_[(1) - (1)].charVal) << std::endl; }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 126 "parser.yy"
    { std::cerr << "String literal: " << *(yysemantic_stack_[(1) - (1)].stringVal) << std::endl; }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 128 "parser.yy"
    { std::cerr << "Function call: " << *(yysemantic_stack_[(4) - (1)].idName) << std::endl; }
    break;



/* Line 678 of lalr1.cc  */
#line 482 "parser.tab.cc"
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
  const signed char Parser::yypact_ninf_ = -51;
  const short int
  Parser::yypact_[] =
  {
         3,   -51,   -51,   -51,   -51,   -51,     6,    13,   -51,   -51,
     -51,     9,   -51,   -51,    18,   -51,   -51,   -51,    15,   -51,
      45,    16,    38,    23,   -51,   109,    32,   109,    14,   -51,
      48,   -51,   -51,   -51,    80,   -51,   -51,   -51,    84,   -51,
      46,    50,    61,    64,   143,   221,   233,   233,   -51,   -51,
      79,   364,   -51,   123,   -51,   -51,   112,    94,   -51,   -51,
     -51,   -51,   -51,   233,   204,   233,   233,   233,   -51,   -51,
      49,   -51,   257,   304,    92,   -51,   -51,   -51,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   -51,   -36,   -51,   -51,   -51,   -51,   158,
     364,   -51,    62,   364,   282,   324,   344,   -51,   -51,   233,
     378,   391,   403,   224,   266,   266,    40,    40,    40,    40,
     -28,   -28,   -51,   -51,   -51,   130,   -51,   -51,   233,   -51,
     -51,   176,   176,   -51,   -51,   364,   120,   -51,   176,   -51
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,    36,    37,    38,    35,    39,     0,     0,    69,    72,
      71,     0,     1,    70,     0,    40,    41,    42,     0,    43,
      44,     0,     0,     0,    46,     0,     0,     0,     0,    75,
       0,    73,    45,    76,     0,    74,     8,     9,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    53,
       0,     3,    59,     0,    57,    48,     0,     0,    49,    50,
      51,    52,    47,     0,     0,     0,     0,     0,    65,    66,
       6,    67,     0,     0,     0,    28,    29,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,    54,    58,    55,    60,     0,
       2,    10,     0,     4,     0,     0,     0,    68,    30,     0,
      23,    22,    17,    18,    25,    24,    19,    20,    27,    26,
      13,    14,    15,    16,    21,     0,    32,    56,     0,    11,
      12,     0,     0,    31,    34,     5,     0,    64,     0,    63
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -51,   -51,   -51,   -44,    81,   -51,   -51,    58,   -51,   -51,
     -50,   -18,    87,   -51,   -51,   -51,   -51,   -51,   -51,   138,
     -51,   -51
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,    50,   102,    51,    52,    94,     6,    53,    21,    22,
      54,    55,    56,    57,    58,    59,    60,    61,     7,     8,
       9,    10
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        72,    73,    75,    76,   125,    31,    96,    90,    91,    92,
      35,   126,    11,    12,     1,     2,     3,     4,     5,   100,
     103,   104,   105,   106,     1,     2,     3,     4,     5,    15,
      16,    17,    18,    19,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    96,
      14,    24,    36,    37,    38,    39,    25,    23,    26,    15,
      16,    17,    30,    19,    40,   133,    41,    42,    43,    44,
      29,    30,    20,    88,    89,    90,    91,    92,    27,    33,
      28,   136,   137,    32,   135,    34,    62,    66,   139,    45,
      64,    67,    65,    46,    47,    48,    30,    49,    36,    37,
      38,    39,   128,    74,   129,    15,    16,    17,    68,    19,
      40,    69,    41,    42,    43,    44,    36,    37,    38,    39,
      15,    16,    17,    63,    19,    64,    77,    65,    40,    93,
      41,    42,    43,    44,   109,    45,   134,   138,    98,    46,
      47,    48,    30,    97,    99,    13,     0,    36,    37,    70,
      39,     0,     0,    45,     0,     0,     0,    46,    47,    48,
      30,    95,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,    41,    42,    43,    44,
      36,    37,    38,    39,    45,     0,     0,     0,    46,    47,
      71,     0,    40,     0,    41,    42,    43,    44,     0,    45,
       0,     0,     0,    46,    47,    48,    30,   127,    36,    37,
      70,    39,     0,     0,     0,     0,     0,    45,     0,     0,
       0,    46,    47,    48,    30,    36,    37,    70,    39,     0,
       0,     0,    15,    16,    17,     0,    19,    36,    37,    70,
      39,     0,     0,     0,     0,    45,   101,     0,     0,    46,
      47,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    45,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,    46,    47,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   107,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,   130,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,   108,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,   131,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,   132,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        44,    45,    46,    47,    40,    23,    56,    35,    36,    37,
      28,    47,     6,     0,    11,    12,    13,    14,    15,    63,
      64,    65,    66,    67,    11,    12,    13,    14,    15,    11,
      12,    13,    14,    15,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    99,
      41,     6,     4,     5,     6,     7,    40,    42,    42,    11,
      12,    13,    48,    15,    16,   109,    18,    19,    20,    21,
      47,    48,    14,    33,    34,    35,    36,    37,    40,    47,
      42,   131,   132,    25,   128,    27,     6,    41,   138,    41,
      41,    41,    43,    45,    46,    47,    48,    49,     4,     5,
       6,     7,    40,    45,    42,    11,    12,    13,    47,    15,
      16,    47,    18,    19,    20,    21,     4,     5,     6,     7,
      11,    12,    13,    39,    15,    41,    47,    43,    16,     6,
      18,    19,    20,    21,    42,    41,     6,    17,    57,    45,
      46,    47,    48,    49,    57,     7,    -1,     4,     5,     6,
       7,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,
       4,     5,     6,     7,    41,    -1,    -1,    -1,    45,    46,
      47,    -1,    16,    -1,    18,    19,    20,    21,    -1,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    47,    48,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,
      46,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    47,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    11,    12,    13,    14,    15,    56,    68,    69,    70,
      71,     6,     0,    69,    41,    11,    12,    13,    14,    15,
      57,    58,    59,    42,     6,    40,    42,    40,    42,    47,
      48,    61,    57,    47,    57,    61,     4,     5,     6,     7,
      16,    18,    19,    20,    21,    41,    45,    46,    47,    49,
      51,    53,    54,    57,    60,    61,    62,    63,    64,    65,
      66,    67,     6,    39,    41,    43,    41,    41,    47,    47,
       6,    47,    53,    53,    57,    53,    53,    47,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     6,    55,    49,    60,    49,    54,    62,
      53,    42,    52,    53,    53,    53,    53,    47,    42,    42,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    40,    47,    49,    40,    42,
      44,    42,    42,    53,     6,    53,    60,    60,    17,    60
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   124,    38,   280,   281,    60,
      62,   282,   283,    43,    45,    42,    47,    37,   284,    61,
      44,    40,    41,    91,    93,    33,   126,    59,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     3,     1,     1,     3,     1,     1,     1,     1,
       3,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     4,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     4,     1,     1,
       1,     1,     1,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     7,     5,     2,     2,     2,     3,     1,
       2,     1,     1,     6,     6,     6,     6
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"character\"", "\"string\"", "\"identificator\"",
  "\"number constant\"", "\"unterminated string constant\"",
  "\"unterminated comment block\"", "\"invalid character literal\"",
  "CHAR", "SHORT", "INT", "VOID", "STRING", "IF", "ELSE", "WHILE",
  "CONTINUE", "BREAK", "RETURN", "LOW_PRIORITY", "OR_OP", "AND_OP", "'|'",
  "'&'", "NE_OP", "EQ_OP", "'<'", "'>'", "GE_OP", "LE_OP", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY_OP", "'='", "','", "'('", "')'", "'['",
  "']'", "'!'", "'~'", "';'", "'{'", "'}'", "$accept",
  "assignment_expression", "argument_expression_list", "expression",
  "declaration", "declarator_list", "function_type", "type_specifier",
  "parameter_types_list", "parameter_definition_list", "statement",
  "compound_statement", "statement_list", "declaration_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "function_declaration", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        68,     0,    -1,     6,    39,    53,    -1,    53,    -1,    53,
      -1,    52,    40,    53,    -1,     6,    -1,     7,    -1,     4,
      -1,     5,    -1,     6,    41,    42,    -1,     6,    41,    52,
      42,    -1,     6,    43,    53,    44,    -1,    53,    33,    53,
      -1,    53,    34,    53,    -1,    53,    35,    53,    -1,    53,
      36,    53,    -1,    53,    25,    53,    -1,    53,    26,    53,
      -1,    53,    29,    53,    -1,    53,    30,    53,    -1,    53,
      37,    53,    -1,    53,    24,    53,    -1,    53,    23,    53,
      -1,    53,    28,    53,    -1,    53,    27,    53,    -1,    53,
      32,    53,    -1,    53,    31,    53,    -1,    45,    53,    -1,
      46,    53,    -1,    41,    53,    42,    -1,    41,    57,    42,
      53,    -1,    57,    55,    47,    -1,     6,    -1,    55,    40,
       6,    -1,    14,    -1,    11,    -1,    12,    -1,    13,    -1,
      15,    -1,    11,    -1,    12,    -1,    13,    -1,    15,    -1,
      57,    -1,    58,    40,    57,    -1,    57,     6,    -1,    59,
      40,    57,     6,    -1,    61,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    48,    49,    -1,    48,    62,    49,
      -1,    48,    63,    49,    -1,    48,    63,    62,    49,    -1,
      60,    -1,    62,    60,    -1,    54,    -1,    63,    54,    -1,
      47,    -1,    51,    47,    -1,    16,    41,    53,    42,    60,
      17,    60,    -1,    18,    41,    53,    42,    60,    -1,    19,
      47,    -1,    20,    47,    -1,    21,    47,    -1,    21,    53,
      47,    -1,    69,    -1,    68,    69,    -1,    71,    -1,    70,
      -1,    56,     6,    41,    14,    42,    61,    -1,    56,     6,
      41,    59,    42,    61,    -1,    56,     6,    41,    14,    42,
      47,    -1,    56,     6,    41,    58,    42,    47,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     7,     9,    11,    15,    17,    19,    21,
      23,    27,    32,    37,    41,    45,    49,    53,    57,    61,
      65,    69,    73,    77,    81,    85,    89,    93,    97,   100,
     103,   107,   112,   116,   118,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   140,   142,   146,   149,   154,   156,
     158,   160,   162,   164,   167,   171,   175,   180,   182,   185,
     187,   190,   192,   195,   203,   209,   212,   215,   218,   222,
     224,   227,   229,   231,   238,   245,   252
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   113,   113,   114,   118,   119,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   152,   156,   157,   161,   162,   163,   164,   165,
     169,   170,   171,   172,   176,   177,   181,   182,   186,   187,
     188,   189,   190,   194,   195,   196,   197,   201,   202,   206,
     207,   211,   212,   217,   221,   225,   226,   227,   228,   232,
     233,   237,   238,   242,   243,   247,   248
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
       2,     2,     2,    45,     2,     2,     2,    37,    26,     2,
      41,    42,    35,    33,    40,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      29,    39,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,    25,    49,    46,     2,     2,     2,
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
      27,    28,    31,    32,    38
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 440;
  const int Parser::yynnts_ = 22;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 50;

  const unsigned int Parser::yyuser_token_number_max_ = 284;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // vype10

/* Line 1054 of lalr1.cc  */
#line 1094 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 251 "parser.yy"
 /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m);
}

