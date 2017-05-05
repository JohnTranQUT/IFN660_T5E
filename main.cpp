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


void outputToScreenType(Type* temp) {
	if (auto _temp = dynamic_cast<NumberType *>(temp))
		puts(to_string(_temp->_getValue()).c_str());
	if (auto _temp = dynamic_cast<StringType *>(temp))
		puts(_temp->_getValue().c_str());
	puts(temp->_getType().c_str());
}

void main(int argc, char *argv[]) {
	auto temp = additiveOperator(new NumberType(1), new NumberType(2));
	outputToScreenType(temp);
	temp = additiveOperator(new StringType("hi"), new NumberType(2));
	outputToScreenType(temp);
	temp = additiveOperator(new NumberType(3), new StringType("hi"));
	outputToScreenType(temp);
	temp = subtractiveOperator(new NumberType(1), new NumberType(2));
	outputToScreenType(temp);
	temp = subtractiveOperator(new StringType("g"), new StringType("o"));
	outputToScreenType(temp);
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
//	addition();
}