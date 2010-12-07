/** ANSI C ANTLR v3 grammar

Adapted for C output target by Jim Idle - April 2007.

Translated from Jutta Degener's 1995 ANSI C yacc grammar by Terence Parr
July 2006.  The lexical rules were taken from the Java grammar.

Jutta says: "In 1985, Jeff Lee published his Yacc grammar (which
is accompanied by a matching Lex specification) for the April 30, 1985 draft
version of the ANSI C standard.  Tom Stockfisch reposted it to net.sources in
1987; that original, as mentioned in the answer to question 17.25 of the
comp.lang.c FAQ, can be ftp'ed from ftp.uu.net,
   file usenet/net.sources/ansi.c.grammar.Z.
I intend to keep this version as close to the current C Standard grammar as
possible; please let me know if you discover discrepancies. Jutta Degener, 1995"

Generally speaking, you need symbol table info to parse C; typedefs
define types and then IDENTIFIERS are either types or plain IDs.  I'm doing
the min necessary here tracking only type names.  This is a good example
of the global scope (called Symbols).  Every rule that declares its usage
of Symbols pushes a new copy on the stack effectively creating a new
symbol scope.  Also note rule declaration declares a rule scope that
lets any invoked rule see isTypedef boolean.  It's much easier than
passing that info down as parameters.  Very clean.  Rule
direct_declarator can then easily determine whether the IDENTIFIER
should be declared as a type name.

I have only tested this on a single file, though it is 3500 lines.

This grammar requires ANTLR v3 (3.0b8 or higher)

Terence Parr
July 2006

*/
grammar vype10;

options 
{
    backtrack	= true;
    memoize	= true;
    k	= 2;
    language	= C;
}



scope Symbols 
{
    // Only track types in order to get parser working. The Java example
    // used the java.util.Set to keep track of these. The ANTLR3 runtime
    // has a number of useful 'objects' we can use that act very much like
    // the Java hashtables, Lists and Vectors. You have finer control over these
    // than the Java programmer, but they are sometimes a little more 'raw'.
    // Here, for each scope level, we want a set of symbols, so we can use
    // a ANTLR3 runtime provided hash table, and then later we will see if
    // a symbols is stored in at any level by using the symbol as the
    // key to the hashtable and seeing if the table contains that key.
    //
    pANTLR3_HASH_TABLE	    types;


}

// While you can implement your own character streams and so on, they
// normally call things like LA() via function pointers. In general you will
// be using one of the pre-supplied input streams and you can instruct the
// generated code to access the input pointers directly.
//
// For  8 bit inputs            : #define ANTLR3_INLINE_INPUT_ASCII
// For 16 bit UTF16/UCS2 inputs : #define ANTLR3_INLINE_INPUT_UTF16
//
// If your compiled recognizer might be given inputs from either of the sources
// or you have written your own character input stream, then do not define
// either of these.
//
@lexer::header
{
#define	ANTLR3_INLINE_INPUT_ASCII
}

@parser::includes
{
}

// The @header specifier is valid in the C target, but in this case there
// is nothing to add over and above the generated code. Here you would
// add #defines perhaps that you have made your code reliant upon.
//
// Use @preincludes for things you want to appear in the output file
//     before #include <antlr3.h>
//     @includes to come after #include <antlr3.h>
//     @header for things that should follow on after all the includes.
//
// Hence, this java oriented @header is commented out.
//
// @header {
// import java.util.Set;
// import java.util.HashSet;
// }

// @members inserts functions in C output file (parser without other
//          qualification. @lexer::members inserts functions in the lexer.
//
// In general do not use this too much (put in the odd tiny function perhaps),
// but include the generated header files in your own header and use this in
// separate translation units that contain support functions.
//
@members 
{



    // This is a function that is small enough to be kept in the
    // generated parser code (@lexer::members puts code in the lexer.
    //
    // Note a few useful MACROS in use here:
    //
    // SCOPE_SIZE     returns the number of levels on the stack (1 to n)
    //                for the named scope.
    // SCOPE_INSTANCE returns a pointer to Scope instance at the
    //                specified level.
    // SCOPE_TYPE     makes it easy to declare and cast the pointer to
    //                the structure typedef that the code generator declares.
    //
    // All functions (that need anything to do with the runtime, should
    // receive a parameter called ctx as the first parameter. ctx is a pointer
    // to the instance of the parser that is running and ensures thread safety
    // as well as easy access to all the parser elements etc. All MACROS assume
    // the presence of this parameter. This would be a pCLexer pointer if this
    // were a function to be called by the lexer (in which case this would be in
    // @lexer::members.
    //
    ANTLR3_BOOLEAN  isTypeName(pCParser ctx, pANTLR3_UINT8 name)
    {
	int	i;

	for (i = (int)SCOPE_SIZE(Symbols)-1 ; i >= 0; i--)
	{
    	pANTLR3_HASH_TABLE  symtab;
    	pANTLR3_STRING		symbol;
	    SCOPE_TYPE(Symbols)	symScope;   // Aids in declaring the scope pointers

    	// Pick up the pointer to the scope structure at the current level
	    // We are descending from the inner most scope as that is how C type
	    // scoping works.
	    //
    	symScope	= (SCOPE_TYPE(Symbols))SCOPE_INSTANCE(Symbols, i);

	    // The pointer we have is an instance of the dynamic global scope
	    // called Symbols. Within there, as declared above, we have a pointer
	    // to an ANTLR3_HASH_TABLE. We should really check for NULL etc, like all good C code 
	    // should. But, this is example code...
	    //
	    symtab		= (pANTLR3_HASH_TABLE) symScope->types;

	    // The following call shows that you cannot add a NULL pointer as the entry for
	    // the hash table. You can always just add the pointer to the key and ignore it, but
	    // when you return from this call, you want to test for a NULL pointer, which means
	    // the entry was not found in the table.
	    //
    	symbol		= (pANTLR3_STRING)	(symtab->get(symtab, (void *)name));
    
	    // Did we find the symbol in the type lists?
	    // This is generally used for semantic predicates, hence ANTLR3_TRUE or ANTLR3_FALSE
	    // for the return
	    //
    	if (symbol != NULL)
    	{
    		return ANTLR3_TRUE;
    	}
	}

	// We did not find the requested symbol in any of the scopes
	// that are currently in force.
	//
	return ANTLR3_FALSE;
    }

    // Because our dynamic scope contains an ANTLR3_HASH_TABLE, we need to free
    // it when it goes out of scope. When we create a new scope, we just set the
    // free pointer for the scope to point to this embedded function, which will be
    // called with a pointer to the scope instance that is to be freed,
    // from whence we take the table pointer, which we can then close :-)
    //
    void ANTLR3_CDECL freeTable(SCOPE_TYPE(Symbols) symtab)
    {
		// If we supplied an entry in the table with a free pointer,
		// then calling the table free function will call the free function
		// for each entry as it deletes it from the table. In this case however
		// we only stored things that were manufactured by internal factories, which
		// will be released anyway when the parser/lexer/etc are freed.
		//
		symtab->types->free(symtab->types);
    }
}

translation_unit

    scope Symbols; // The entire translation_unit (file) is a scope

    @init 
    {
		// The code in @init is executed before the rule starts. Note that this
		// is C, hence we cannot guarantee to be able to both declare and initialize
		// variables at the same time. If you need to declare variables as local
		// to a rule, use the @declarations section and then initialize locals
		// separately in this @init section.
		//
		$Symbols::types = antlr3HashTableNew(11);	// parameter is a rough hint for hash alg. as to size

		SCOPE_TOP(Symbols)->free	= freeTable;	// This is called when the scope is popped
    }


    : external_declaration+
    ;

/** Either a function definition or any other kind of C decl/def.
 *  The LL(*) analysis algorithm fails to deal with this due to
 *  recursion in the declarator rules.  I'm putting in a
 *  manual predicate here so that we don't backtrack over
 *  the entire function.  Further, you get a better error
 *  as errors within the function itself don't make it fail
 *  to predict that it's a function.  Weird errors previously.
 *  Remember: the goal is to avoid backtrack like the plague
 *  because it makes debugging, actions, and errors harder.
 *
 *  Note that k=1 results in a much smaller predictor for the 
 *  fixed lookahead; k=2 made a few extra thousand lines. ;)
 *  I'll have to optimize that in the future.
 */
external_declaration
    options 
    {
		k=1;
    }
    : ( type_specifier? direct_declarator declaration* '{' )=> function_definition
    | declaration
    ;

function_definition

    scope Symbols; // put parameters and locals into same scope for now

    @init 
    {
      $Symbols::types = antlr3HashTableNew(11);
      SCOPE_TOP(Symbols)->free	= freeTable;	// This is called when the scope is popped
    }
    :	type_specifier? direct_declarator
    	(	compound_statement				// ANSI style
	)
    ;

declaration
    scope 
    {
		ANTLR3_BOOLEAN	    isTypedef;
    }
    @init 
    {
		$declaration::isTypedef = ANTLR3_FALSE;
    }
    :  type_specifier init_declarator_list? ';'
    ;

init_declarator_list
    : init_declarator (',' init_declarator)*
    ;

init_declarator
    : direct_declarator ('=' initializer)?
    ;

type_specifier
    : 'void'
    | 'char'
    | 'short'
    | 'int'
    | 'string'
    ;

specifier_qualifier_list
    : ( type_specifier )+
    ;

direct_declarator
    :   (   IDENTIFIER
			{
	    		if (SCOPE_TOP(declaration) != NULL && $declaration::isTypedef)
				{
					pANTLR3_STRING idText;

					// When adding an element to a pANTLR3_HASH_TABLE, the first argument
					// is the hash table itself, the second is the entry key, the third is
					// a (void *) pointer to a structure or element of your choice (cannot
					// be NULL) and the 4th is a pointer to a function that knows how to free
					// your entry structure (if this is needed, give NULL if not) when the table
					// is destroyed, or the entry is deleted from the table.
					//
					idText = $IDENTIFIER.text;
					$Symbols::types->put($Symbols::types, idText->chars, idText, NULL);


					// Note that we must escape the percent sign here from ANTLR expression
					// parsing. It is not seen in the generated C code.
					//
					printf("define type \%s\n", $IDENTIFIER.text->chars);
				}
			}
		  | '(' direct_declarator ')'
	)

        declarator_suffix*
    ;

declarator_suffix
    :   '(' parameter_list ')'
    |   '(' identifier_list ')'
    |   '(' ')'
    ;

parameter_list
    : parameter_declaration (',' parameter_declaration)*
    ;

parameter_declaration
    : type_specifier (direct_declarator)*
    ;

identifier_list
    : IDENTIFIER (',' IDENTIFIER)*
    ;
	
initializer
    : assignment_expression
    ;

// E x p r e s s i o n s

argument_expression_list
    :   assignment_expression (',' assignment_expression)*
    ;

additive_expression
    : (multiplicative_expression) ('+' multiplicative_expression | '-' multiplicative_expression)*
    ;

multiplicative_expression
    : (cast_expression) ('*' cast_expression | '/' cast_expression | '%' cast_expression)*
    ;

cast_expression
    : '(' type_specifier ')' cast_expression
    | postfix_expression
    ;

postfix_expression
    :   primary_expression
		(     '[' expression ']'
			| '(' ')'
			| '(' argument_expression_list ')'
			| '*' IDENTIFIER
        )*
    ;

unary_operator
    : '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'
    ;

primary_expression
    : IDENTIFIER
    | constant
    | '(' expression ')'
    ;

constant
    :   DECIMAL_LITERAL
    |	CHARACTER_LITERAL
    |	STRING_LITERAL
    ;

/////

expression
    : assignment_expression (',' assignment_expression)*
    ;


assignment_expression
    : lvalue assignment_operator assignment_expression
    ;
	
lvalue
    :	postfix_expression
    ;

assignment_operator
    : '='
    ;

logical_or_expression
    : logical_and_expression ('||' logical_and_expression)*
    ;

logical_and_expression
    : inclusive_or_expression ('&&' inclusive_or_expression)*
    ;

inclusive_or_expression
    : and_expression ('|' and_expression)*
    ;

and_expression
    : equality_expression ('&' equality_expression)*
    ;

equality_expression
    : relational_expression (('=='|'!=') relational_expression)*
    ;

relational_expression
    : additive_expression (('<'|'>'|'<='|'>=') additive_expression)*
    ;

// S t a t e m e n t s

statement
    : compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

compound_statement
    scope Symbols; // blocks have a scope of symbols
    @init 
    {
	$Symbols::types = antlr3HashTableNew(11);
	SCOPE_TOP(Symbols)->free	= freeTable;	// This is called when the scope is popped
    }
    : '{' declaration* statement_list? '}'
    ;

statement_list
    : statement+
    ;

expression_statement
    : ';'
    | expression ';'
    ;

selection_statement
    : 'if' '(' expression ')' statement (('else')=> 'else' statement)?
    ;

iteration_statement
    : 'while' '(' expression ')' statement
//    | 'for' '(' expression_statement expression_statement expression? ')' statement
    ;

jump_statement
    :  'continue' ';'
    | 'break' ';'
    | 'return' ';'
    | 'return' expression ';'
    ;

IDENTIFIER
    :	LETTER (LETTER|'0'..'9')*
    ;
	
fragment
LETTER
    :	'$'
    |	'A'..'Z'
    |	'a'..'z'
    |	'_'
    ;

CHARACTER_LITERAL
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

STRING_LITERAL
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    ;

DECIMAL_LITERAL : ('0' | '1'..'9' '0'..'9'*) ;

fragment
EscapeSequence
    :   '\\' ('t'|'n'|'\"'|'\''|'\\')
    ;

WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
    ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;
