#define _CRT_SECURE_NO_DEPRECATE
#include <Type.h>
#include <operator.h>
#include <math.h>
#include <string>
#include <iostream>
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
	
	Number * x = new Number(+0);
	Number * y = new Number(-32);
	String * a = new String("little");
	String * b = new String("progress"); 
	Symbol * c = new Symbol();
	String * d = new String("");
	addition(x, y);
	addition(a, b);
	addition(x, a);
	addition(b, y);
	ToBoolean(c);
	ToBoolean(d);

#endif
}
