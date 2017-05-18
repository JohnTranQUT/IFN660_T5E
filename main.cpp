#include <cstdio>
#include <RuntimeLib\RuntimeLib.h>
#include <string>


//#include <parser.h>
//extern FILE *yyin;
//using namespace std;


void outputToScreenType(LanguageType* temp) {
	if (auto _temp = dynamic_cast<NumberType *>(temp))
		puts(to_string(_temp->_getValue()).c_str());
	if (auto _temp = dynamic_cast<StringType *>(temp))
		puts(_temp->_getValue().c_str());
}

void main(int argc, char *argv[]) {
	/* ADDITION TESTING */
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
	auto temp2 = new EnvironmentRecord();
	auto e1 = new Reference(temp2, new StringType("x"), new BooleanType(false), nullptr);
	auto e2 = new NumberType(42);
	auto e3 = Assignment(e1, e2);
	auto e4 = new Reference(temp2, new StringType("y"), new BooleanType(false), nullptr);
	auto e0 = new NumberType(1);
	auto e5 = Additive(e1, e0);
	auto e6 = Assignment(e4, e5);
	outputToScreenType(GetValue(e4));

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