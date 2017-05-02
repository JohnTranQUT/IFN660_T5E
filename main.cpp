#define _CRT_SECURE_NO_DEPRECATE
#include <RuntimeLib/Types/LanguageTypes/LanguageTypesFunc.h>
#include <RuntimeLib/Objects/ObjectConstructor.h>
#include <RuntimeLib/Utilities/Operator/Operator.h>
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

#ifdef SA
	puts("\nBasic LanguageTypes Demo\n");

	_calculate(new StringType("Hello"), "+", new NullType());
	_calculate(new NumberType(50), "-", new BooleanType(false));
	_calculate(new UndefinedType(), "*", new NumberType(20));
	_calculate(new BooleanType(true), "/", new StringType("1000"));
	_calculate(new StringType("20"), "%", new NumberType(5));

	puts("\nObjectType/Objects Demo\n");

	_calculate(String(new StringType("World")), "+", Object());
	_calculate(Object(new BooleanType(false)), "-", Number(new NumberType(20)));
	_calculate(Object(new NumberType(5)), "*", Object(new StringType("2")));
	_calculate(String(new StringType("30")), "/", Object(Object(Object(Boolean(new BooleanType(true))))));
	_calculate(Boolean(new BooleanType(true)), "%", String(new StringType("3")));

	puts("");
#endif

}
