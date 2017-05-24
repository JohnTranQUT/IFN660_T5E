#include <iostream>
#include "AST/AstScript.h"

using namespace std;

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
	fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	GeneratingCode(argv[1], root);
	getchar();
}