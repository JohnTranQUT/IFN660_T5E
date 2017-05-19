#include <iostream>
#include "AST/AstScript.h"
using namespace std;

int yylex();
int yyparse();

extern FILE *yyin;
extern Script *root;
int CounterLabel = 0;

void CodeGeneration(char* inputfile, Script* root)
{
	char* outputFilename = (char *)malloc(strlen(inputfile) + 1);
	outputFilename[strlen(inputfile) - 3] = '\0'; //insert end string charracter
	memcpy(outputFilename, inputfile + 0 /* Offset */, (strlen(inputfile)-3) /* Length */);
	sprintf(outputFilename, "%s.cpp", outputFilename);
	FILE* outputFile = fopen(outputFilename, "w");
	//include header files
	root->emit(outputFile, "#include \"RuntimeLib/SpecificationType/LexicalEnvironment.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/RuntimeSemantic.h\"");
	root->emit(outputFile, "#include \"RuntimeLib/Operation.h\"");
	root->emit(outputFile, "#include <iostream>");
	//main function
	root->emit(outputFile, "int main(int argc, char* argv[])");
	root->emit(outputFile, "{");
	//global environment
	root->emit(outputFile, "LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);");
	root->GenCode(outputFile);
	//log the value to test
	root->emit(outputFile, "std::cout << dynamic_cast<JSValue*>(r%d)->ToString();", CounterLabel - 1);
	root->emit(outputFile, "}"); // end of Main
}
int main(int argc, char* argv[]) {
	fopen_s(&yyin, argv[1], "r");
	yyparse();
	root->dump(0);
	CodeGeneration(argv[1], root);
	getchar();
}
