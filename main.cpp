#include <cstdio>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>

#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>

//#include <parser.h>
//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
	auto temp = additiveOperator(new StringType("version"), new NumberType(2));
	auto _temp = dynamic_cast<StringType *>(temp);
	puts(_temp->_getValue().c_str());
	puts(_temp->_getType().c_str());
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
//	addition();
}
