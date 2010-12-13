
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
#line 93 "parser.yy"


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
#line 119 "parser.yy"
    { std::cerr << "Identifier: " << *(yysemantic_stack_[(1) - (1)].idName) << std::endl; }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 120 "parser.yy"
    { std::cerr << "Int constant: " << (yysemantic_stack_[(1) - (1)].integerVal) << std::endl; }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 121 "parser.yy"
    { std::cerr << "Character literal: " << (yysemantic_stack_[(1) - (1)].charVal) << std::endl; }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 122 "parser.yy"
    { std::cerr << "String literal: " << *(yysemantic_stack_[(1) - (1)].stringVal) << std::endl; }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 124 "parser.yy"
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
        42,   -51,   -51,   -51,   -51,   -51,    12,     4,   -51,   -51,
     -51,   -33,   -51,   -51,    68,   -51,   -51,   -51,    -6,   -51,
      56,    53,    91,    90,   -51,    -1,    64,    -1,    38,   -51,
      51,   -51,   -51,   -51,    80,   -51,   -51,   -51,    93,   -51,
      85,   107,   102,   104,   182,   209,   223,   223,   -51,   -51,
     106,   354,   -51,   143,   -51,   -51,   109,    94,   -51,   -51,
     -51,   -51,   -51,   223,   195,   223,   223,   223,   -51,   -51,
     103,   -51,   247,   294,    52,   -51,   -51,   -51,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   -51,   -27,   -51,   -51,   -51,   -51,   152,
     354,   -51,   105,   354,   272,   314,   334,   -51,   -51,   223,
     368,   381,   393,   404,    -2,    -2,    87,    87,    87,    87,
      39,    39,   -51,   -51,   -51,   154,   -51,   -51,   223,   -51,
     -51,   167,   167,   -51,   -51,   354,   147,   -51,   167,   -51
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
       -51,   -51,   -51,   -44,   118,   -51,   -51,    60,   -51,   -51,
     -50,    47,   119,   -51,   -51,   -51,   -51,   -51,   -51,   155,
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
        72,    73,    75,    76,    12,    14,    96,    15,    16,    17,
     125,    19,     1,     2,     3,     4,     5,   126,    11,   100,
     103,   104,   105,   106,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    23,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    96,
       1,     2,     3,     4,     5,    36,    37,    38,    39,    15,
      16,    17,    24,    19,    40,   133,    41,    42,    43,    44,
      31,    90,    91,    92,    20,    35,    15,    16,    17,    18,
      19,   136,   137,    30,   135,    32,    62,    34,   139,    45,
      25,   109,    26,    46,    47,    48,    30,    49,    36,    37,
      38,    39,    15,    16,    17,    74,    19,    40,    33,    41,
      42,    43,    44,    36,    37,    38,    39,    88,    89,    90,
      91,    92,    40,    66,    41,    42,    43,    44,    27,    63,
      28,    64,    45,    65,    29,    30,    46,    47,    48,    30,
      97,    64,   128,    65,   129,    67,    68,    45,    69,    93,
      77,    46,    47,    48,    30,    95,    36,    37,    38,    39,
     134,   138,    13,     0,     0,    40,     0,    41,    42,    43,
      44,    36,    37,    38,    39,    98,    99,     0,     0,     0,
      40,     0,    41,    42,    43,    44,    36,    37,    70,    39,
      45,     0,     0,     0,    46,    47,    48,    30,   127,    36,
      37,    70,    39,     0,     0,    45,     0,     0,     0,    46,
      47,    48,    30,    36,    37,    70,    39,    15,    16,    17,
      45,    19,     0,     0,    46,    47,    71,    36,    37,    70,
      39,     0,     0,    45,   101,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,    46,    47,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       0,     0,     0,   130,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,   108,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,   131,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,   132,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        44,    45,    46,    47,     0,    38,    56,     8,     9,    10,
      37,    12,     8,     9,    10,    11,    12,    44,     6,    63,
      64,    65,    66,    67,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    39,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    99,
       8,     9,    10,    11,    12,     4,     5,     6,     7,     8,
       9,    10,     6,    12,    13,   109,    15,    16,    17,    18,
      23,    32,    33,    34,    14,    28,     8,     9,    10,    11,
      12,   131,   132,    45,   128,    25,     6,    27,   138,    38,
      37,    39,    39,    42,    43,    44,    45,    46,     4,     5,
       6,     7,     8,     9,    10,    45,    12,    13,    44,    15,
      16,    17,    18,     4,     5,     6,     7,    30,    31,    32,
      33,    34,    13,    38,    15,    16,    17,    18,    37,    36,
      39,    38,    38,    40,    44,    45,    42,    43,    44,    45,
      46,    38,    37,    40,    39,    38,    44,    38,    44,     6,
      44,    42,    43,    44,    45,    46,     4,     5,     6,     7,
       6,    14,     7,    -1,    -1,    13,    -1,    15,    16,    17,
      18,     4,     5,     6,     7,    57,    57,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    18,     4,     5,     6,     7,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,     4,
       5,     6,     7,    -1,    -1,    38,    -1,    -1,    -1,    42,
      43,    44,    45,     4,     5,     6,     7,     8,     9,    10,
      38,    12,    -1,    -1,    42,    43,    44,     4,     5,     6,
       7,    -1,    -1,    38,    39,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    43,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     8,     9,    10,    11,    12,    53,    65,    66,    67,
      68,     6,     0,    66,    38,     8,     9,    10,    11,    12,
      54,    55,    56,    39,     6,    37,    39,    37,    39,    44,
      45,    58,    54,    44,    54,    58,     4,     5,     6,     7,
      13,    15,    16,    17,    18,    38,    42,    43,    44,    46,
      48,    50,    51,    54,    57,    58,    59,    60,    61,    62,
      63,    64,     6,    36,    38,    40,    38,    38,    44,    44,
       6,    44,    50,    50,    54,    50,    50,    44,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,    52,    46,    57,    46,    51,    59,
      50,    39,    49,    50,    50,    50,    50,    44,    39,    39,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    37,    44,    46,    37,    39,
      41,    39,    39,    50,     6,    50,    57,    57,    14,    57
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   124,    38,   277,   278,    60,    62,   279,   280,
      43,    45,    42,    47,    37,   281,    61,    44,    40,    41,
      91,    93,    33,   126,    59,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68
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
  "\"number constant\"", "CHAR", "SHORT", "INT", "VOID", "STRING", "IF",
  "ELSE", "WHILE", "CONTINUE", "BREAK", "RETURN", "LOW_PRIORITY", "OR_OP",
  "AND_OP", "'|'", "'&'", "NE_OP", "EQ_OP", "'<'", "'>'", "GE_OP", "LE_OP",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_OP", "'='", "','", "'('",
  "')'", "'['", "']'", "'!'", "'~'", "';'", "'{'", "'}'", "$accept",
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
        65,     0,    -1,     6,    36,    50,    -1,    50,    -1,    50,
      -1,    49,    37,    50,    -1,     6,    -1,     7,    -1,     4,
      -1,     5,    -1,     6,    38,    39,    -1,     6,    38,    49,
      39,    -1,     6,    40,    50,    41,    -1,    50,    30,    50,
      -1,    50,    31,    50,    -1,    50,    32,    50,    -1,    50,
      33,    50,    -1,    50,    22,    50,    -1,    50,    23,    50,
      -1,    50,    26,    50,    -1,    50,    27,    50,    -1,    50,
      34,    50,    -1,    50,    21,    50,    -1,    50,    20,    50,
      -1,    50,    25,    50,    -1,    50,    24,    50,    -1,    50,
      29,    50,    -1,    50,    28,    50,    -1,    42,    50,    -1,
      43,    50,    -1,    38,    50,    39,    -1,    38,    54,    39,
      50,    -1,    54,    52,    44,    -1,     6,    -1,    52,    37,
       6,    -1,    11,    -1,     8,    -1,     9,    -1,    10,    -1,
      12,    -1,     8,    -1,     9,    -1,    10,    -1,    12,    -1,
      54,    -1,    55,    37,    54,    -1,    54,     6,    -1,    56,
      37,    54,     6,    -1,    58,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    45,    46,    -1,    45,    59,    46,
      -1,    45,    60,    46,    -1,    45,    60,    59,    46,    -1,
      57,    -1,    59,    57,    -1,    51,    -1,    60,    51,    -1,
      44,    -1,    48,    44,    -1,    13,    38,    50,    39,    57,
      14,    57,    -1,    15,    38,    50,    39,    57,    -1,    16,
      44,    -1,    17,    44,    -1,    18,    44,    -1,    18,    50,
      44,    -1,    66,    -1,    65,    66,    -1,    68,    -1,    67,
      -1,    53,     6,    38,    11,    39,    58,    -1,    53,     6,
      38,    56,    39,    58,    -1,    53,     6,    38,    11,    39,
      44,    -1,    53,     6,    38,    55,    39,    44,    -1
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
         0,   109,   109,   110,   114,   115,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   148,   152,   153,   157,   158,   159,   160,   161,
     165,   166,   167,   168,   172,   173,   177,   178,   182,   183,
     184,   185,   186,   190,   191,   192,   193,   197,   198,   202,
     203,   207,   208,   213,   217,   221,   222,   223,   224,   228,
     229,   233,   234,   238,   239,   243,   244
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
       2,     2,     2,    42,     2,     2,     2,    34,    23,     2,
      38,    39,    32,    30,    37,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      26,    36,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    22,    46,    43,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    24,    25,    28,
      29,    35
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 438;
  const int Parser::yynnts_ = 22;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 47;

  const unsigned int Parser::yyuser_token_number_max_ = 281;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // vype10

/* Line 1054 of lalr1.cc  */
#line 1090 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 247 "parser.yy"
 /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l, const std::string& m)
{
    compiler.error(l, m, RET_ERR_SYNTACTICAL);
}

