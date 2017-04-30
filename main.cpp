#define _CRT_SECURE_NO_DEPRECATE
#include <Types/LanguageTypes/LanguageTypesFunc.h>
#include <Utilities/Operator/Operator.h>
#include <parser.h>
#include <Objects/ObjectObject/ObjectObject.h>
#include <Objects/BooleanObject/BooleanObject.h>

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

	_calculate(new BooleanObject(new BooleanType(true)), "+", new ObjectObject(new ObjectType()));
	_calculate(new ObjectObject(new NullType()), "-", new NumberObject(new NumberType(20)));
	_calculate(new ObjectObject(new NumberType(5)), "*", new ObjectObject(new UndefinedType()));
	_calculate(new StringObject(new StringType("World")), "/", new ObjectObject(new ObjectObject(new ObjectObject(new BooleanObject(new BooleanType(false))))));
	_calculate(new BooleanObject(new BooleanType(true)), "%", new StringObject(new StringType("3")));

	puts("\nToObject() Demo");

	puts("\nBooleanType to BooleanObject\n");
	auto boolean = new BooleanType(true);
	printf("Original Value: %s (BooleanType)\n", ToString(boolean)->_getValue().c_str());
	printf("Converted Value: %s / %s (BooleanObject)\n", dynamic_cast<ObjectObject*>(ToObject(boolean))->prototype.toString()->_getValue().c_str(), dynamic_cast<BooleanObject*>(ToObject(boolean))->prototype.toString()->_getValue().c_str());

	puts("\nNumberType to NumberObject\n");
	auto number = new NumberType(20);
	printf("Original Value: %s (NumberType)\n", ToString(number)->_getValue().c_str());
	printf("Converted Value: %s / %s (NumberObject)\n", dynamic_cast<ObjectObject*>(ToObject(number))->prototype.toString()->_getValue().c_str(), dynamic_cast<NumberObject*>(ToObject(number))->prototype.toString()->_getValue().c_str());

	puts("\nStringType to StringObject\n");
	auto string = new StringType("Hello");
	printf("Original Value: %s (StringType)\n", ToString(string)->_getValue().c_str());
	printf("Converted Value: %s / %s (StringObject)\n", dynamic_cast<ObjectObject*>(ToObject(string))->prototype.toString()->_getValue().c_str(), dynamic_cast<StringObject*>(ToObject(string))->prototype.toString()->_getValue().c_str());

	puts("");
#endif

}
