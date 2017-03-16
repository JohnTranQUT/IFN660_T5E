%{
	#include <cstdio>
	int yylex();
	void yyerror(char*);
%}

%union {
	int num;
	char* name;
}

%token <num> NUMBER
%token <name> IDENT
%token IF ELSE INT BOOL

%left '='
%nonassoc '<'
%left '+'

%%

Program : Statement
	;

Statement : IF '(' Expression ')' Statement ELSE Statement
	| '{' StatementList '}'
	| Expression ';'
	| Type IDENT ';'
	;

Type : INT
	| BOOL
	;

StatementList : StatementList Statement
	| /* empty */
	;

Expression : NUMBER
	| IDENT
	| Expression '=' Expression
	| Expression '+' Expression
	| Expression '<' Expression
	;

%%
