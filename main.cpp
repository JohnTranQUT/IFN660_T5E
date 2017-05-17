#include <iostream>
#include "RuntimeLib/Operation.h"
#include "RuntimeLib/JSValue/JSValue.h"
#include "AST/AstNode.h"
#include "AST/AstScript.h"


//#define testParser

int yylex();
int yyparse();

extern FILE *yyin;
extern Node *root;



int main(int argc, char* argv[]) {

	fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	getchar();

}
