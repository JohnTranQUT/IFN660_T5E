#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <js_type.h>
#include <operator.h>
//#include <parser.h>

//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
	addition(new String("Hello"), new NullType());
	addition(new Number(50), new Boolean(false));
	addition(new NullType(), new Number(20));
	addition(new Boolean(true), new String("1000"));
	addition(new String("20"), new Number(5));
	addition(new Number(3.14), new String(""));

	subtraction(new Number(50), new Boolean(false));
	subtraction(new NullType(), new Number(20));
	subtraction(new Boolean(true), new String("1000"));
	subtraction(new String("20"), new Number(5));
	subtraction(new Number(3.14), new String(""));
	subtraction(new String("Hello"), new NullType());
}
