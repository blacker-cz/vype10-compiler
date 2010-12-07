
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

#include <stdio.h>
#include <string>
#include <vector>



/* Line 311 of lalr1.cc  */
#line 52 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 84 "parser.yy"


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
	

/* Line 678 of lalr1.cc  */
#line 447 "parser.tab.cc"
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
  const signed char Parser::yypact_ninf_ = -73;
  const short int
  Parser::yypact_[] =
  {
        47,   -73,   -73,   -73,   -73,   -73,    38,   111,   -73,   -73,
     -73,    41,   -73,   -73,   141,   -73,   -73,   -73,    43,   -73,
      69,    -8,    -6,   -39,   -73,    39,   150,    51,   150,   -73,
      74,   -73,   -73,   -73,   -73,    86,   -73,    48,   -73,    83,
      88,    77,    78,   182,   212,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,    89,   242,   -73,   -24,    -1,    22,    91,
      92,    95,   127,   132,   -73,   103,   -73,   142,   -73,   -73,
     148,   118,   -73,   -73,   -73,   -73,   -73,   227,   242,   242,
     242,   -73,   -73,   -73,   104,   137,   149,   242,   -73,   -73,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   -73,   -73,   -23,   -73,   -73,
     -73,   -73,   178,   -73,    29,   -73,   146,   151,   159,   -73,
     -73,   242,   -73,   -73,   -73,   -73,   -24,   -24,    -1,    -1,
      -1,    -1,    22,    22,    91,    92,    95,   127,   171,   -73,
     -73,   -73,   242,   -73,     3,     3,   -73,   -73,   -73,   169,
     -73,     3,   -73
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,    50,    51,    52,    49,    53,     0,     0,    84,    87,
      86,     0,     1,    85,     0,    54,    55,    56,     0,    57,
      58,     0,     0,     0,    60,     0,     0,     0,     0,    90,
       0,    88,    91,    59,    89,     0,     4,     2,     3,     0,
       0,     0,     0,     0,     0,    14,    15,    16,    17,    75,
      67,     6,    12,    18,     0,    20,    24,    27,    32,    35,
      37,    39,    41,    43,    45,     0,    73,     0,    71,    62,
       0,     0,    63,    64,    65,    66,    61,     0,     0,     0,
       0,    80,    81,    82,     0,     0,     0,     0,    18,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    47,     0,    68,    72,
      69,    74,     0,     8,     0,    10,     0,     0,     0,    83,
       5,     0,    44,    21,    22,    23,    26,    25,    30,    31,
      28,    29,    33,    34,    36,    38,    40,    42,     0,    46,
      70,     9,     0,     7,     0,     0,    19,    48,    11,    77,
      79,     0,    78
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -73,   -73,   -73,   -73,   -30,   -73,   -53,     9,   -11,    10,
      93,    94,    90,   100,   -73,   -72,   -27,   124,   -73,   -73,
      28,   -73,   -73,   -68,    44,   134,   -73,   -73,   -73,   -73,
     -73,   -73,   191,   -73,   -73
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,    51,    52,   114,    88,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   107,     6,
      67,    21,    22,    68,    69,    70,    71,    72,    73,    74,
      75,     7,     8,     9,    10
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        53,    89,   109,    29,    30,   115,   138,    36,    37,    38,
      90,    91,    92,    53,    53,   122,    84,    85,    25,   139,
      27,    26,    39,    28,    40,    41,    42,    43,    44,    95,
      96,    93,    94,    45,    46,    47,    48,   123,   124,   125,
      53,    53,    20,    11,   109,    49,    30,    53,    53,    53,
      53,   116,   117,   118,    33,   141,    35,    53,   142,    97,
      98,     1,     2,     3,     4,     5,    14,    31,   146,    23,
     148,    34,    86,    77,    24,    78,   149,   150,    36,    37,
      38,    32,    53,   152,   128,   129,   130,   131,    15,    16,
      17,    76,    19,    39,    30,    40,    41,    42,    43,    44,
      99,   100,   126,   127,    45,    46,    47,    48,    79,   132,
     133,    12,    53,    80,    53,    53,    49,    30,    50,    81,
      82,    53,    36,    37,    38,     1,     2,     3,     4,     5,
      87,   101,    15,    16,    17,   102,    19,    39,   103,    40,
      41,    42,    43,    44,   104,   105,   119,   106,    45,    46,
      47,    48,    36,    37,    38,    15,    16,    17,    18,    19,
      49,    30,   110,   120,    15,    16,    17,    39,    19,    40,
      41,    42,    43,    44,   143,   121,   147,   144,    45,    46,
      47,    48,    36,    37,    38,   145,    36,    37,    38,   151,
      49,    30,   108,   136,   134,   111,   135,    39,    13,    40,
      41,    42,    43,    44,   137,   112,     0,    44,    45,    46,
      47,    48,    45,    46,    47,    48,    36,    37,    38,     0,
      49,    30,   140,     0,    83,     0,    15,    16,    17,     0,
      19,    36,    37,    38,     0,     0,     0,    44,     0,     0,
       0,     0,    45,    46,    47,    48,    36,    37,    38,     0,
       0,     0,    44,   113,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    45,    46,    47,    48
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        30,    54,    70,    42,    43,    77,    29,     4,     5,     6,
      34,    35,    36,    43,    44,    87,    43,    44,    26,    42,
      26,    29,    19,    29,    21,    22,    23,    24,    25,     7,
       8,    32,    33,    30,    31,    32,    33,    90,    91,    92,
      70,    71,    14,     5,   112,    42,    43,    77,    78,    79,
      80,    78,    79,    80,    26,    26,    28,    87,    29,    37,
      38,    14,    15,    16,    17,    18,    25,    23,   121,    26,
     142,    27,    44,    25,     5,    27,   144,   145,     4,     5,
       6,    42,   112,   151,    95,    96,    97,    98,    14,    15,
      16,     5,    18,    19,    43,    21,    22,    23,    24,    25,
       9,    10,    93,    94,    30,    31,    32,    33,    25,    99,
     100,     0,   142,    25,   144,   145,    42,    43,    44,    42,
      42,   151,     4,     5,     6,    14,    15,    16,    17,    18,
      41,    39,    14,    15,    16,    40,    18,    19,    11,    21,
      22,    23,    24,    25,    12,    42,    42,     5,    30,    31,
      32,    33,     4,     5,     6,    14,    15,    16,    17,    18,
      42,    43,    44,    26,    14,    15,    16,    19,    18,    21,
      22,    23,    24,    25,    28,    26,     5,    26,    30,    31,
      32,    33,     4,     5,     6,    26,     4,     5,     6,    20,
      42,    43,    44,   103,   101,    71,   102,    19,     7,    21,
      22,    23,    24,    25,   104,    71,    -1,    25,    30,    31,
      32,    33,    30,    31,    32,    33,     4,     5,     6,    -1,
      42,    43,    44,    -1,    42,    -1,    14,    15,    16,    -1,
      18,     4,     5,     6,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,     4,     5,     6,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    33
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    14,    15,    16,    17,    18,    64,    76,    77,    78,
      79,     5,     0,    77,    25,    14,    15,    16,    17,    18,
      65,    66,    67,    26,     5,    26,    29,    26,    29,    42,
      43,    69,    42,    65,    69,    65,     4,     5,     6,    19,
      21,    22,    23,    24,    25,    30,    31,    32,    33,    42,
      44,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    65,    68,    69,
      70,    71,    72,    73,    74,    75,     5,    25,    27,    25,
      25,    42,    42,    42,    61,    61,    65,    41,    49,    51,
      34,    35,    36,    32,    33,     7,     8,    37,    38,     9,
      10,    39,    40,    11,    12,    42,     5,    63,    44,    68,
      44,    62,    70,    26,    48,    60,    61,    61,    61,    42,
      26,    26,    60,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    55,    56,    57,    58,    29,    42,
      44,    26,    29,    28,    26,    26,    51,     5,    60,    68,
      68,    20,    68
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,    91,    93,    44,
     126,    33,    45,    43,    42,    47,    37,    60,    62,    38,
     124,    61,    59,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    45,    46,    46,    46,    46,    47,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    63,    63,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     1,     1,     1,     1,     1,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       2,     2,     2,     3,     1,     2,     1,     1,     6,     6,
       6,     6
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"string\"", "\"identificator\"", "\"number constant\"", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "TYPE_NAME", "CHAR",
  "SHORT", "INT", "VOID", "STRING", "IF", "ELSE", "WHILE", "CONTINUE",
  "BREAK", "RETURN", "'('", "')'", "'['", "']'", "','", "'~'", "'!'",
  "'-'", "'+'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'|'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "and_expression", "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "expression",
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
        76,     0,    -1,     5,    -1,     6,    -1,     4,    -1,    25,
      61,    26,    -1,    46,    -1,     5,    27,    61,    28,    -1,
       5,    25,    26,    -1,     5,    25,    48,    26,    -1,    60,
      -1,    48,    29,    60,    -1,    47,    -1,    50,    51,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    49,    -1,
      25,    65,    26,    51,    -1,    51,    -1,    52,    34,    51,
      -1,    52,    35,    51,    -1,    52,    36,    51,    -1,    52,
      -1,    53,    33,    52,    -1,    53,    32,    52,    -1,    53,
      -1,    54,    37,    53,    -1,    54,    38,    53,    -1,    54,
       7,    53,    -1,    54,     8,    53,    -1,    54,    -1,    55,
       9,    54,    -1,    55,    10,    54,    -1,    55,    -1,    56,
      39,    55,    -1,    56,    -1,    57,    40,    56,    -1,    57,
      -1,    58,    11,    57,    -1,    58,    -1,    59,    12,    58,
      -1,    59,    -1,    49,    41,    60,    -1,    60,    -1,    65,
      63,    42,    -1,     5,    -1,    63,    29,     5,    -1,    17,
      -1,    14,    -1,    15,    -1,    16,    -1,    18,    -1,    14,
      -1,    15,    -1,    16,    -1,    18,    -1,    65,    -1,    66,
      29,    65,    -1,    65,     5,    -1,    67,    29,    65,     5,
      -1,    69,    -1,    72,    -1,    73,    -1,    74,    -1,    75,
      -1,    43,    44,    -1,    43,    70,    44,    -1,    43,    71,
      44,    -1,    43,    71,    70,    44,    -1,    68,    -1,    70,
      68,    -1,    62,    -1,    71,    62,    -1,    42,    -1,    61,
      42,    -1,    19,    25,    61,    26,    68,    -1,    19,    25,
      61,    26,    68,    20,    68,    -1,    21,    25,    61,    26,
      68,    -1,    22,    42,    -1,    23,    42,    -1,    24,    42,
      -1,    24,    61,    42,    -1,    77,    -1,    76,    77,    -1,
      79,    -1,    78,    -1,    64,     5,    25,    17,    26,    69,
      -1,    64,     5,    25,    67,    26,    69,    -1,    64,     5,
      25,    17,    26,    42,    -1,    64,     5,    25,    66,    26,
      42,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    31,    35,    37,    40,    42,    44,    46,    48,    50,
      55,    57,    61,    65,    69,    71,    75,    79,    81,    85,
      89,    93,    97,    99,   103,   107,   109,   113,   115,   119,
     121,   125,   127,   131,   133,   137,   139,   143,   145,   149,
     151,   153,   155,   157,   159,   161,   163,   165,   167,   169,
     173,   176,   181,   183,   185,   187,   189,   191,   194,   198,
     202,   207,   209,   212,   214,   217,   219,   222,   228,   236,
     242,   245,   248,   251,   255,   257,   260,   262,   264,   271,
     278,   285
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   100,   100,   101,   102,   103,   107,   108,   109,   110,
     114,   115,   119,   120,   124,   125,   126,   127,   131,   132,
     136,   137,   138,   139,   143,   144,   145,   149,   150,   151,
     152,   153,   157,   158,   159,   163,   164,   168,   169,   173,
     174,   178,   179,   183,   184,   188,   192,   196,   197,   201,
     202,   203,   204,   205,   209,   210,   211,   212,   216,   217,
     221,   222,   226,   227,   228,   229,   230,   234,   235,   236,
     237,   241,   242,   246,   247,   251,   252,   256,   257,   261,
     265,   266,   267,   268,   272,   273,   277,   278,   282,   283,
     287,   288
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
       2,     2,     2,    31,     2,     2,     2,    36,    39,     2,
      25,    26,    34,    33,    29,    32,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      37,    41,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    40,    44,    30,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 275;
  const int Parser::yynnts_ = 35;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 45;

  const unsigned int Parser::yyuser_token_number_max_ = 279;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // vype10

/* Line 1054 of lalr1.cc  */
#line 1046 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 291 "parser.yy"
 /*** Additional Code ***/

void vype10::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    compiler.error(l, m);
}

