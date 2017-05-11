#define _CRT_SECURE_NO_DEPRECATE
#include <limits>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/ObjectConstructor.h>
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>
#include <RuntimeLib/_Helpers/_Helpers.h>
#include <parser.h>
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironmentFunc.h>
#include <RuntimeLib/Evaluations/Expression/AssignmentOperators/AssignmentOperators.h>
#include <RuntimeLib/Evaluations/Expression/Identifiers/Identifiers.h>
#include <RuntimeLib/ExecutionContexts/ExecutionContexts.h>

#define AST
#define SA
#define ER_BASIC
#define ER

extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {

#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
#endif

#ifdef SA
	puts("\nBasic LanguageType Test\n");

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

#ifdef ER_BASIC

	puts("<<<JS");
	puts("\tlet x;");
	puts("\tx = 42;");
	puts("JS;");
	puts("");

	auto DeclarEnvER_B = new DeclarativeEnvironmentRecord();
	InitializeBoundName(new StringType("x"), new UndefinedType(), DeclarEnvER_B); // BindingIdentifier : Identifier

	auto LexEnvER_B = new LexicalEnvironment(DeclarEnvER_B);

	auto xrefER_B = ResolveBinding(new StringType("x"), LexEnvER_B); // IdentifierReference : Identifier
	auto xvalueER_B = new NumberType(42); // NumericLiteral

	SimpleAssignmentOperator(xrefER_B, xvalueER_B); // AssignmentExpression : IdentifierReference = NumericLiteral

	_listItemsInRecord(LexEnvER_B->_getEnvRec());
	puts("");

#endif

#ifdef ER

	puts("<<<JS");
	puts("\tlet x;");
	puts("\tlet y;");
	puts("\tx = 660;");
	puts("\ty = \"IFN\" + x;");
	puts("JS;");
	puts("");

	auto DeclarEnvER = new DeclarativeEnvironmentRecord();
	InitializeBoundName(new StringType("x"), new UndefinedType(), DeclarEnvER); // BindingIdentifier : Identifier
	InitializeBoundName(new StringType("y"), new UndefinedType(), DeclarEnvER); // BindingIdentifier : Identifier

	auto LexEnvER = new LexicalEnvironment(DeclarEnvER);

	auto xrefER = ResolveBinding(new StringType("x"), LexEnvER); // IdentifierReference : Identifier
	auto xvalueER = new NumberType(660); // NumericLiteral

	SimpleAssignmentOperator(xrefER, xvalueER);

	auto yref = ResolveBinding(new StringType("y"), LexEnvER); // IdentifierReference : Identifier
	auto yconcatleft = new StringType("IFN"); // StringLiteral
	auto yconcatright = ResolveBinding(new StringType("x"), LexEnvER); // IdentifierReference : Identifier
	auto yvalue = AdditionOperator(yconcatleft, yconcatright); // AdditiveExpression : StringLiteral + IdentifierReference

	SimpleAssignmentOperator(yref, yvalue); // AssignmentExpression : IdentifierReference = AdditiveExpression

	_listItemsInRecord(LexEnvER->_getEnvRec());
	puts("");

#endif

}
