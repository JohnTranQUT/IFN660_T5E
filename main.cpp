#include <iostream>
#include "RuntimeLib/Operator.h"
#include "RuntimeLib/JSValue.h"
#include "AST/AstNode.h"


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
	printf("hhhee");
	root->dump(0);
	getchar();

#endif


#ifdef testRuntimeLib
	JSNumber* js_number = new JSNumber(3);
	JSBoolean* js_bool = new JSBoolean(true);
	
	JSValue* result = addition(js_number, js_bool);
	std::cout << result->ToString()<<"\n";

	JSString* js_string = new JSString("3.14");
	result = addition(js_string, js_number);
	std::cout << result->ToString() << "\n";
#endif

}
