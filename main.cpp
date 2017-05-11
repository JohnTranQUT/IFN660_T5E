#define _CRT_SECURE_NO_DEPRECATE
#include <limits>
#include <parser.h>
#include <RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <RuntimeLib/Types/LanguageTypes/NullType/NullType.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/ObjectConstructor.h>
#include <RuntimeLib/Evaluations/Expression/AssignmentOperators/AssignmentOperators.h>
#include <RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h>
#include <RuntimeLib/ExecutionContexts/ExecutionContexts.h>
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironmentFunc.h>
#include <RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h>
#include <RuntimeLib/_Helpers/_Helpers.h>

#define AST
#define ARITH
#define ER_B1
#define ER_B2
#define ER

extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {

#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
#endif

#ifdef ARITH
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

#ifdef ER_B1

	puts("ER_B1\n");

	puts("<<<JS");
	puts("\tlet x;");
	puts("\tx = 42;");
	puts("JS;");
	puts("");

	auto LexEnvER_B1 = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	LexEnvER_B1->_getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false)); // Block : BlockDeclarationInstantiation

	InitializeReferencedBinding(ResolveBinding(new StringType("x"), LexEnvER_B1), new UndefinedType()); // LexicalBinding : BindingIdentifier

	auto xrefER_B1 = ResolveBinding(new StringType("x"), LexEnvER_B1); // IdentifierReference : Identifier
	auto xvalueER_B1 = new NumberType(42); // NumericLiteral
	
	SimpleAssignmentOperator(xrefER_B1, xvalueER_B1); // AssignmentExpression : IdentifierReference = NumericLiteral

	_listItemsInRecord(LexEnvER_B1->_getEnvRec());
	puts("");

#endif

#ifdef ER_B2

	puts("ER_B2\n");

	puts("<<<JS");
	puts("\tlet x = 42;");
	puts("JS;");
	puts("");

	auto LexEnvER_B2 = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	LexEnvER_B1->_getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false)); // Block : BlockDeclarationInstantiation

	InitializeReferencedBinding(ResolveBinding(new StringType("x"), LexEnvER_B1), new NumberType(42)); // LexicalBinding : BindingIdentifier Initializer
	
	_listItemsInRecord(LexEnvER_B1->_getEnvRec());
	puts("");

#endif

#ifdef ER

	puts("ER\n");

	puts("<<<JS");
	puts("\tlet x = 660;");
	puts("\tlet y;");
	puts("\ty = \"IFN\" + x;");
	puts("JS;");
	puts("");

	auto LexEnvER = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	// Block : BlockDeclarationInstantiation
	LexEnvER->_getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false));
	LexEnvER->_getEnvRec()->CreateMutableBinding(new StringType("y"), new BooleanType(false));

	
	InitializeReferencedBinding(ResolveBinding(new StringType("x"), LexEnvER), new NumberType(660)); // LexicalBinding : BindingIdentifier Initializer
	InitializeReferencedBinding(ResolveBinding(new StringType("y"), LexEnvER), new UndefinedType()); // LexicalBinding : BindingIdentifier

	auto yref = ResolveBinding(new StringType("y"), LexEnvER); // IdentifierReference : Identifier
	auto yconcatleft = new StringType("IFN"); // StringLiteral
	auto yconcatright = ResolveBinding(new StringType("x"), LexEnvER); // IdentifierReference : Identifier
	auto yvalue = AdditionOperator(yconcatleft, yconcatright); // AdditiveExpression : StringLiteral + IdentifierReference

	SimpleAssignmentOperator(yref, yvalue); // AssignmentExpression : IdentifierReference = AdditiveExpression

	_listItemsInRecord(LexEnvER->_getEnvRec());
	puts("");

#endif

}
