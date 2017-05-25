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
	FILE* outputFile = fopen(argv[2], "w");
	root->eval(0, outputFile);
	printf("Finish code gen");
}