%code requires {
	#include <cstdio>
	#include "ast.h"
	int yylex();
	void yyerror(char*);
}

%union {
	char* regex;
	char* str;
	char* numberStr;
	bool booelan;
	char* ident;
	
	Script* script;
	Statement* statement;
	Expression* expression;
}

%token COMMENT NULL_L
%token <regex> REGEX_LITERAL
%token <str> STRING_L
%token <numberStr> NUMERIC_L
%token <bool> BooleanLiteral
%token <ident> IDENT

%token BREAK DO IN TYPEOF CASE ELSE INSTANCEOF VAR CATCH EXPORT NEW VOID CLASS EXTENDS RETURN WHILE CONST FINALLY SUPER WITH CONTINUE FOR SWITCH YIELD DEBUGGER FUNCTION THIS DEFAULT IF THROW DELETE IMPORT TRY AWAIT ENUM TDOT LE GE EQ DIFF EQTYPE DFTYPE INCREASE DECREASE LSHIFT RSHIFT URSHIFT LOGAND LOOR ADDASS SUBASS MULASS REMASS LSHIFTASS RSHIFTASS URSHIFTASS BWANDASS BWORASS BWXORASS ARROWF EXP EXPASS DIVASS LINE_TERM

%type <script> Script
%type <statement> Statement ExpressionStatement
%type <expression> AssignmentExpression IdentifierReference Literal Identifier DecimalLiteral Expression

%start Script

%%

Script
	: Statement														{ $$ = new Script($1); $$->dump(); }
	;

Statement
	: ExpressionStatement											{ $$ = $1; }
	;

ExpressionStatement
	: Expression ';'												{ $$ = new ExpressionStatement($1); }
	;

Expression
	: AssignmentExpression											{ $$ = $1; }
	;

AssignmentExpression
	: IdentifierReference '=' Literal								{ $$ = new AssignmentExpression($1, $3); }
	;

IdentifierReference
	: Identifier													{ $$ = new IdentifierReference($1); }
	;

Literal
	: DecimalLiteral												{ $$ = new Literal($1); }
	;

Identifier
	: IDENT															{ $$ = new Identifier($1); }
	;

DecimalLiteral
	: NUMERIC_L														{ $$ = new DecimalLiteral($1); }
	;

%%
