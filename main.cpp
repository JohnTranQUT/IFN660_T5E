#include <cstdio>
#include <RuntimeLib\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\LanguageType\NullType\NullType.h>
#include <RuntimeLib\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\LanguageType\ObjectType\ObjectType.h>
#include <RuntimeLib\LanguageType\StringType\StringType.h>
#include <RuntimeLib\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\LanguageType\UndefinedType\UndefinedType.h>

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
