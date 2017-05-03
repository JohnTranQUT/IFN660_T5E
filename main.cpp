#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <Type.h>
#include <operator.h>
//#include <parser.h>

#define AST 
#define SA

//extern FILE *yyin;
//using namespace std;

void main(int argc, char *argv[]) {
/*
#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
#endif
*/
#ifdef SA
	Number x(23), y(32);
	Number * xx = &x;
	Number * yy = &y;
	String a ("little"), b = ("progress");
	String * aa = &a;
	String * bb = &b;
	addition(xx,yy);
	cout << endl;
	addition(aa, bb);

#endif
}
