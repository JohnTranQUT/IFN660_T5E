#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <RuntimeLib\Type\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\NullType\NullType.h>
#include <RuntimeLib\Type\NumberType\NumberType.h>
#include <RuntimeLib\Type\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\StringType\StringType.h>
#include <RuntimeLib\Type\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\UndefinedType\UndefinedType.h>

#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>

//#include <parser.h>
//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
	auto temp = additiveOperator(new NumberType(1), new NumberType(2));
	auto _temp = dynamic_cast<NumberType *>(temp);
	puts(to_string(_temp->_getValue()));
	puts(_temp->_getType());
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
//	addition();
}
