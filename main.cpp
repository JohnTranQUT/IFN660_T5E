#include "parser.h";


int yylex();
int yyparse();

extern FILE *yyin;
extern Node *root;

int LastLabel = 0;
int LastLocal = 0;

int main(int argc, char* argv[]) {

	fopen_s(&yyin, argv[1], "r");
	yyparse();
	//root->dump();
	FILE* outputFile = fopen(argv[2], "w");
	fprintf(outputFile, "#include \"RTLib.h\"\n");
	fprintf(outputFile, "int main(){\n");
	fprintf(outputFile, "LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);\n");
	root->eval(0, outputFile);
	fprintf(outputFile, "}");
	printf("Finish code gen");
}