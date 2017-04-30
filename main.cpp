#include <iostream>
#include "RuntimeLib/Operator.h"
#include "RuntimeLib/Type.h"
#include "AST/AstNode.h"
#include "AST/AstScript.h"


//#define testRuntimeLib
#define testParser

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


#ifdef testRuntimeLib
	NumberType* jsNumber = new NumberType(3);
	BooleanType* jsBool = new BooleanType(true);
	
	Type* result = addition(jsNumber, jsBool);
	std::cout << result->ToString()<<"\n";

	StringType* js_string = new StringType("3.14");
	result = addition(js_string, jsNumber);
	std::cout << result->ToString() << "\n";
#endif

}
