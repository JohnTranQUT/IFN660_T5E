#include <iostream>
#include "RuntimeLib/JSValue/JSValue.h"
#include "AST/AstScript.h"
#include "RuntimeLib/SpecificationType/LexicalEnvironment.h"
#include "RuntimeLib/RuntimeSemantic.h"
#include "RuntimeLib/Operation.h"




int yylex();
int yyparse();

extern FILE *yyin;
extern Script *root;



int main(int argc, char* argv[]) {

	fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	getchar();
	//
	LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);
	Type* r0 = ResolveBinding("x", lexEnv);
	Type* r1 = new NumberValue(42);
	Type* r2 = assignment(r0, r1);
	Type* r3 = ResolveBinding("y", lexEnv);
	Type* r4 = ResolveBinding("x", lexEnv);
	Type* r5 = new NumberValue(1);
	Type* r6 = addition(r4, r5);
	Type* r7 = assignment(r3, r6);
	std::cout << dynamic_cast<JSValue*>(r7)->ToString();
	getchar();
}
