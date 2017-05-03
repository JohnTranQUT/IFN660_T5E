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

#ifdef testParser
	fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	getchar();
#endif


#ifdef DEBUG
	addition(new BooleanValue(true), new StringValue("Hello World"));
	addition(new NumberValue(3.14), new NumberValue(2));
	addition(new UndefinedValue(), new NumberValue(2));
	addition(new UndefinedValue(), new StringValue("QUT"));
	addition(new NullValue(), new NumberValue(2));
	addition(new NumberValue(NAN), new BooleanValue(false));
#endif

}
