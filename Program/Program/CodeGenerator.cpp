#include <iostream>
#include "AST/AstScript.h"

using namespace std;

int yylex();
int yyparse();


extern FILE *yyin;
extern Script *root;

int Counter = 0;

void GeneratingCode(char* input, Script* root) {

	char* outputFilename = (char*)malloc(strlen(inputfile) + 1);
	sprintf(outputFilename, "%s.cpp", inputfile);
	FILE* outputFile = fopen(outputFilename, "generetedFile");

	//Header Files
	root->emit(outputFile, "#include \"RuntimeLib/SpecificationType/LexicalEnvironment.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/RuntimeSemantic.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/Operation.h\"");
	root->emit(outputFile, "#include <iostream>");


}