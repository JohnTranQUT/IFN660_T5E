#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <LanguageTypes.h>
#include <operator.h>
//#include <parser.h>

//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
	auto lhs = new BooleanType(true);
	auto rhs = new NumberType(20);
	auto result = addition(lhs, rhs);
	printf("%s\n", result->dump().c_str());
}
