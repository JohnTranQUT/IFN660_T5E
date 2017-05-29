#include <cstdio>
#include <RuntimeLib\RuntimeLib.h>
#include <string>
#include <parser.h>
#include <fstream>

extern FILE *yyin;
extern Node *root;
extern ofstream outfile;
using namespace std;


void main(int argc, char *argv[]) {
	puts("========AST TEST========");
	fopen_s(&yyin, argv[1], "r");
	puts("========File Read========");
	yyparse();
	puts("========File Parsed========");
	outfile.open(argv[2]);
	root->genCode(new int(1));
	//root->dump();
	outfile.close();
}

void outputToScreenType(Type* temp) {
	if (auto _temp = dynamic_cast<NumberType *>(temp))
		puts(to_string(_temp->_getValue()).c_str());
	if (auto _temp = dynamic_cast<StringType *>(temp))
		puts(_temp->_getValue().c_str());
	if (auto _temp = dynamic_cast<LexicalEnvironment *>(temp)) {
		_temp->getEnvRec()->dumpEnvRecords();
	}
}

void equalityTest() {
	puts("========Equality TESTING========");
	auto test = Equality(new NumberType(1), new NumberType(1), "==" );
}

void additionTest() {
	/* ADDITION TESTING */
	puts("========ADDITION TESTING========");
	auto temp = Additive(new NumberType(1), new NumberType(2));
	outputToScreenType(temp);
	temp = Additive(new StringType("hi"), new NumberType(2));
	outputToScreenType(temp);
	temp = Additive(new NumberType(3), new StringType("hi"));
	outputToScreenType(temp);
	temp = Additive(new StringType("hi"), new StringType("john"));
	outputToScreenType(temp);
	temp = Subtractive(new NumberType(1), new NumberType(2));
	outputToScreenType(temp);
	temp = Subtractive(new StringType("g0"), new StringType("ao"));
	outputToScreenType(temp);
}

void yxTest() {
	//Type* e1 = ResolveName("x", env);
	puts("======== X = 42; Y = X + 1; TESTING========");
	auto r1 = NewDeclarativeEnvironment();
	auto r2 = new StringType("x");
	auto r3 = ResolveBinding(r2, r1);
	//auto rX1 = r1->getEnvRec()->CreateMutableBinding(r2, new BooleanType(false));
	//auto rY1 = r1->getEnvRec()->CreateMutableBinding(r3, new BooleanType(false));
	//auto rX2 = InitializeReferencedBinding(ResolveBinding(r2, r1), new UndefinedType());
	//auto rY2 = InitializeReferencedBinding(ResolveBinding(r3, r1), new UndefinedType());
	auto r4 = new NumberType(42);
	auto r5 = Assignment(r3, r4);
	auto r6 = new StringType("y");
	auto r7 = new StringType("x");
	auto r8 = new NumberType(1);
	auto r9 = ResolveBinding(r7, r1);
	auto r10 = Additive(r9, r8);
	auto r11 = ResolveBinding(r6, r1);
	auto r12 = Assignment(r11, r10);
	puts("========Y RESULT========");
	outputToScreenType(GetValue(ResolveBinding(new StringType("y"), r1)));
	puts("========LEXICAL ENVIRONMENT RECORDS DUMP========");
	outputToScreenType(r1);
}