#define _CRT_SECURE_NO_DEPRECATE
#include <limits>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypesFunc.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/ObjectConstructor.h>
#include <RuntimeLib/_Helpers/_Helpers.h>
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
	puts("\nBasic LanguageTypes Test\n");

	_calculate(new StringType("Hello"), "+", new NullType());
	_calculate(new NumberType(50), "-", new BooleanType(false));
	_calculate(new UndefinedType(), "*", new NumberType(20));
	_calculate(new BooleanType(true), "/", new StringType("1000"));
	_calculate(new StringType("20"), "%", new NumberType(5));

	puts("\nObjectType/Objects Test\n");

	_calculate(String(new StringType("World")), "+", Object());
	_calculate(Object(new BooleanType(false)), "-", Number(new NumberType(20)));
	_calculate(Object(new NumberType(5)), "*", Object(new StringType("2")));
	_calculate(String(new StringType("30")), "/", Object(Object(Object(Boolean(new BooleanType(true))))));
	_calculate(Boolean(new BooleanType(true)), "%", String(new StringType("3")));

	puts("\nInfinity/NaN Test\n");

	puts("+\n");
	_calculate(new NumberType(NAN), "+", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "+", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "+", new NumberType(-INFINITY));
	_calculate(new NumberType(-INFINITY), "+", new NumberType(-INFINITY));
	_calculate(new NumberType(INFINITY), "+", new BooleanType(true));

	puts("\n-\n");
	_calculate(new NumberType(NAN), "-", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "-", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "-", new NumberType(-INFINITY));
	_calculate(new NumberType(-INFINITY), "-", new NumberType(-INFINITY));
	_calculate(new NumberType(-INFINITY), "-", new BooleanType(true));

	puts("\n*\n");
	_calculate(new NumberType(NAN), "*", new NumberType(NAN));
	_calculate(new NumberType(NAN), "*", new BooleanType(true));
	_calculate(new NumberType(INFINITY), "*", new BooleanType(false));
	_calculate(new NumberType(INFINITY), "*", new NumberType(-INFINITY));

	puts("\n/\n");
	_calculate(new NumberType(NAN), "/", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "/", new NumberType(INFINITY));
	_calculate(new NumberType(INFINITY), "/", new BooleanType(true));
	_calculate(new BooleanType(true), "/", new NumberType(INFINITY));
	_calculate(new BooleanType(false), "/", new BooleanType(false));
	_calculate(new BooleanType(true), "/", new BooleanType(false));

	puts("\n%\n");
	_calculate(new NumberType(NAN), "%", new NumberType(NAN));
	_calculate(new NumberType(INFINITY), "%", new BooleanType(false));
	_calculate(new BooleanType(false), "%", new NumberType(-INFINITY));
	_calculate(new BooleanType(false), "%", new BooleanType(true));

	puts("");
#endif

}
