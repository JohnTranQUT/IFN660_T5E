#include <cstdio>
#include <parser.h>

extern FILE *yyin;

using namespace std;
void main(int argc, char *argv[]) {
	fopen_s(&yyin, argv[1], "r");	
	yyparse();
}
