#include <iostream>
#include "RuntimeLib/JSValue/JSValue.h"
#include "AST/AstScript.h"
#include "RuntimeLib/SpecificationType/LexicalEnvironment.h"
#include "RuntimeLib/RuntimeSemantic.h"
#include "RuntimeLib/Operation.h"
#include <parser.h>





int yylex();
int yyparse();

extern FILE *yyin;
extern Script *root;


int Counter = 0;

void GeneratingCode(char* input, Script* root) {

	char* outputFilename = (char*)malloc(strlen(input) + 1);
	sprintf(outputFilename, "%s.cpp", input);
	FILE* outputFile = fopen(outputFilename, "generetedFile");

	//Header Files
	root->emit(outputFile, "#include \"RuntimeLib/SpecificationType/LexicalEnvironment.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/RuntimeSemantic.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/Operation.h\"");
	root->emit(outputFile, "#include <iostream>");
	//Main function

	root->emit(outputFile, "int main(int argc, char* argv[])");
	root->emit(outputFile, "{");

	//global environment

	root->emit(outputFile, "LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);");
	root->GenCode(outputFile);

	//value logging

	root->emit(outputFile, "std::cout << dynamic_cast<JSValue*>(r%d)->ToString();", Counter - 1);
	root->emit(outputFile, "}");

}
int main(int argc, char* argv[]) {

	/*fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	getchar();*/
	
	/*LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);

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

	GeneratingCode(argv[1], root);*/
	puts("1");
}

