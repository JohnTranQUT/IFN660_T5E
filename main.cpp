#define _CRT_SECURE_NO_DEPRECATE
#include <limits>
#include <parser.h>
#include <fstream>
#include "RuntimeLib.h"

#define INC_AST
//#define AST
//#define ARITH
//#define ER_B1
//#define ER_B2
//#define ER
#define CG

extern FILE *yyin;
extern Node *root;

int Node::numRef = 1;
int Node::numLex = 1;
int Node::indent = 0;
vector<string> Node::refs;
vector<string> Node::lexs;
ofstream output;

using namespace std;

void main(int argc, char *argv[]) {

#ifdef INC_AST

	fopen_s(&yyin, argv[1], "r");
	yyparse();

#endif

#ifdef AST
	root->dump();
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

	auto ER_B1_1 = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	// ----- DECLARATION SCAN - START -----

	// let BindingIdentifier
	auto ER_B1_2 = new StringType("x");
	auto ER_B1_3 = ER_B1_1->_getEnvRec()->CreateMutableBinding(ER_B1_2, new BooleanType(false)); // Block : BlockDeclarationInstantiation

	// ----- DECLARATION SCAN - END -----

	// ----- ExecUTION - START -----

	// let BindingIdentifier
	auto ER_B1_4 = new StringType("x");
	auto ER_B1_5 = ResolveBinding(ER_B1_4, ER_B1_1);

	auto ER_B1_6 = InitializeReferencedBinding(ER_B1_5, new UndefinedType()); // LexicalBinding : BindingIdentifier

	auto ER_B1_7 = new NumberType(42); // NumericLiteral

	auto ER_B1_8 = new StringType("x"); // Identifier : IdentifierName
	auto ER_B1_9 = ResolveBinding(ER_B1_8, ER_B1_1); // IdentifierReference : Identifier
	
	auto ER_B1_10 = SimpleAssignmentOperator(ER_B1_9, ER_B1_7); // AssignmentExpression : IdentifierReference = NumericLiteral

	// ----- ExecUTION - END -----

	_listItemsInRecord(ER_B1_1->_getEnvRec());
	puts("");

#endif

#ifdef ER_B2

	puts("ER_B2\n");

	puts("<<<JS");
	puts("\tlet x = 42;");
	puts("JS;");
	puts("");

	auto ER_B2_1 = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	// ----- DECLARATION SCAN - START -----

	auto ER_B2_2 = new StringType("x"); // let BindingIdentifier
	auto ER_B2_3 = ER_B2_1->_getEnvRec()->CreateMutableBinding(ER_B2_2, new BooleanType(false)); // Block : BlockDeclarationInstantiation

	// ----- DECLARATION SCAN - END -----

	// ----- ExecUTION - START -----

	auto ER_B2_4 = new NumberType(42); // Initializer : = NumericLiteral

	// let BindingIdentifier
	auto ER_B2_5 = new StringType("x");
	auto ER_B2_6 = ResolveBinding(ER_B2_5, ER_B2_1);

	auto ER_B2_7 = InitializeReferencedBinding(ER_B2_6, ER_B2_4); // LexicalBinding : BindingIdentifier Initializer

	// ----- ExecUTION - END -----

	_listItemsInRecord(ER_B2_1->_getEnvRec());
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

	auto ER_1 = NewDeclarativeEnvironment(nullptr); // Block : Evaluation

	// ----- DECLARATION SCAN - START -----

	// let BindingIdentifier
	auto ER_2 = new StringType("x");
	auto ER_3 = ER_1->_getEnvRec()->CreateMutableBinding(ER_2, new BooleanType(false));

	// let BindingIdentifier
	auto ER_4 = new StringType("y");
	auto ER_5 = ER_1->_getEnvRec()->CreateMutableBinding(ER_4, new BooleanType(false));

	// ----- DECLARATION SCAN - END -----

	// ----- ExecUTION - START -----
	
	auto ER_6 = new NumberType(660); // Initializer : = NumericLiteral

	// let BindingIdentifier
	auto ER_7 = new StringType("x");
	auto ER_8 = ResolveBinding(ER_7, ER_1);

	auto ER_9 = InitializeReferencedBinding(ER_8, ER_6); // LexicalBinding : BindingIdentifier Initializer

	// let BindingIdentifier
	auto ER_10 = new StringType("y");
	auto ER_11 = ResolveBinding(ER_10, ER_1);

	auto ER_12 = InitializeReferencedBinding(ER_11, new UndefinedType()); // LexicalBinding : BindingIdentifier

	auto ER_13 = new StringType("IFN"); // StringLiteral

	auto ER_14 = new StringType("x"); // Identifier : IdentifierName
	auto ER_15 = ResolveBinding(ER_14, ER_1); // IdentifierReference : Identifier
	auto ER_16 = AdditionOperator(ER_13, ER_15); // AdditiveExpression : StringLiteral + IdentifierReference

	auto ER_17 = new StringType("y"); // Identifier : IdentifierName
	auto ER_18 = ResolveBinding(ER_17, ER_1); // IdentifierReference : Identifier
	auto ER_19 = SimpleAssignmentOperator(ER_18, ER_16); // AssignmentExpression : IdentifierReference = AdditiveExpression

	// ----- ExecUTION - END -----

	_listItemsInRecord(ER_1->_getEnvRec());
	puts("");

#endif

#ifdef CG

	output.open(argv[2], ofstream::out | ofstream::trunc);
	root->evaluate();
	output.close();
	puts("");

#endif

}
