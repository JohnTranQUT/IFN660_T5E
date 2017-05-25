#define _CRT_SECURE_NO_DEPRECATE
#include <math.h>
#include <string>
#include <iostream>
#include <parser.h>
#include <fstream>

#define AST 
#define SA

extern FILE *yyin;
extern Node *root;
using namespace std;
ofstream SaveFile;

void main(int argc, char *argv[]) {

#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
	SaveFile.open("output.cpp");
	root->Gecode();
	SaveFile.close();


#endif


}
