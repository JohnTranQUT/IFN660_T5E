#include <stdio.h>
#include "AST\AstScript.h"
#include "parser.h"

using namespace std;

extern FILE *yyin;
extern Script *root;

int CounterLabel = 0;


void CodeGeneration(char* inputfile, Script* root)
{
	int namecount = 0;
	char* outputFilename = (char*)malloc(strlen(inputfile) + 3);
	while ((inputfile[namecount] != '.') && (namecount < strlen(inputfile))) {
		outputFilename[namecount] = inputfile[namecount];
		namecount++;
	}
	outputFilename[namecount] = '\0'; //insert end string charracter
	sprintf(outputFilename, "%s.cpp", outputFilename);
	FILE* outputFile = fopen(outputFilename, "w");

	// this toy language doesn't have classes or methods so we need to create a dummy class and main method to host user code ...
	root->emit(outputFile, "#include \"RuntimeLib\\RTlib.h\"", inputfile);
	root->emit(outputFile, "void main(int argc, char *argv[]) {", inputfile);
	root->emit(outputFile, "LexicalEnvironment* globalenv = NewDeclarativeEnvironment(nullptr);");

	root->GenCode(outputFile);
	
	root->emit(outputFile, "");
	root->emit(outputFile, "}"); // end of Main
}

int main(int argc, char* argv[])
{

#ifdef testScanner
	int token = 1;
	while (token > 0)
	{
		token = yylex();
		switch (token)
		{
			case IDENT: printf("IDENT %s\n", yylval.name); break;
			case NUMBER: printf("NUMBER %d\n", yylval.num); break;
			case INT: printf("INT\n"); break;
			case BOOL: printf("BOOL\n"); break;
			case IF: printf("IF\n"); break;
			case ELSE: printf("ELSE\n"); break;
			case EOF: printf("EOF\n"); break;
			default: printf("'%c'\n", token);
		}
	}
#else


		fopen_s(&yyin, argv[1], "r");
		yyparse();

		CodeGeneration(argv[1], root);
		getchar();

#endif
}
