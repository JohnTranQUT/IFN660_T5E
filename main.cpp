#define _CRT_SECURE_NO_DEPRECATE
#include <math.h>
#include <string>
#include <iostream>
#include <parser.h>

#define AST 
#define SA

extern FILE *yyin;
using namespace std;


void main(int argc, char *argv[]) {

#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();

#endif


}
