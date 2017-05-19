#include <cstdio>
#include <RuntimeLib\RuntimeLib.h>
#include <string>


//#include <parser.h>
//extern FILE *yyin;
//using namespace std;


void outputToScreenType(Type* temp) {
	if (auto _temp = dynamic_cast<NumberType *>(temp))
		puts(to_string(_temp->_getValue()).c_str());
	if (auto _temp = dynamic_cast<StringType *>(temp))
		puts(_temp->_getValue().c_str());
	if (auto _temp = dynamic_cast<LexicalEnvironment *>(temp)) {
		_temp->getEnvRec()->dumpEnvRecords();
	}
}

void main(int argc, char *argv[]) {
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

	/* FOR TESTING*/

	//Type* e1 = ResolveName("x", env);
	puts("======== X = 42; Y = X + 1 TESTING========");
	auto r1 = NewDeclarativeEnvironment();
	auto r2 = r1->getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false));
	auto r3 = r1->getEnvRec()->CreateMutableBinding(new StringType("y"), new BooleanType(false));
	auto r4 = InitializedReferencedBinding(ResolveBinding(new StringType("x"), r1), new UndefinedType());
	auto r5 = InitializedReferencedBinding(ResolveBinding(new StringType("y"), r1), new UndefinedType());
	auto r6 = new NumberType(42);
	auto r7 = Assignment(ResolveBinding(new StringType("x"),r1), r6);
	auto r8 = new NumberType(1);
	auto r9 = Additive(ResolveBinding(new StringType("x"), r1), r8);
	auto r10 = Assignment(ResolveBinding(new StringType("y"), r1), r9);
	puts("========Y RESULT========");
	outputToScreenType(GetValue(ResolveBinding(new StringType("y"), r1)));
	puts("========LEXICAL ENVIRONMENT RECORDS DUMP========");
	outputToScreenType(r1);

	/* Real Code
	** let x;
	** let y;
	** x = 42;
	** y = x + 1;
	** for x = 41
	*/

	/*
	Type* r1 = NewDeclaretiveEnv(nullptr);
	Type* r2 = r1->getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false));
	Type* r3 = r1->getEnvRec()->CreateMutableBinding(new StringType("x"), new BooleanType(false));

	Type* r4 = ResolveBinding(new StringType("x"), r1);

	Type* r5 = InitializeReferencedBinding(ResolveBinding(new StringType("x"), r1), new UndefinedType()));
	Type* r6 = 
	
	Type* r4 = r1->getEnvRec()->
	*/


	//fopen_s(&yyin, argv[1], "r");
	//yyparse();
}