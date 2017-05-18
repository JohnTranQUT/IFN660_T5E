#include "RuntimeLib\RTlib.h"
//#define TESTNUM 12

//using namespace std;


void main(int argc, char *argv[]) {
	//double test[TESTNUM] = { 1, 10, -9, INFINITY, INFINITY, -INFINITY, -INFINITY, NAN, 1000, -2156, 0, -0 };
	//for (int i = 0; i < TESTNUM-1; i++) {
	//		auto temp = additiveOperator(new NumberType(test[i]), new NumberType(test[i+1]));
	//		auto _temp = dynamic_cast<NumberType *>(temp);
	//		puts(to_string(_temp->_getValue()).c_str());
	//		puts(_temp->_getType().c_str());
	//}

	/*
	LexicalEnv = NewDeclarativeEnvironment(nullptr);
	LexicalEnv->getEnvironmentRecord()->CreateMutableBinding(new Stringtype("x"), new BooleanType(False));
	InitializeReferencedBinding(ResolveBinding(string("x"), LexicalEnv), new UndefinedType());
	auto xref = ResolveBinding(new StringType("x"), LexicalEnv);
	auto xvalue = new NumberType(42);
	SimpleAssignmentOperator(xref, xvalue);
	*/
	LexicalEnvironment* globalenv = NewDeclarativeEnvironment(nullptr);
	//let x;

	//x = 42;
	Type* e1 = ResolveBinding("x", globalenv);
	Type* e2 = new NumberType(42);
	Type* e3 = assignment(e1, e2);
	//y = x + 2;
	Type* e4 = ResolveBinding("x", globalenv);
	Type* e5 = new NumberType(2);
	Type* e6 = additiveOperator(e4, e5);
	Type* e7 = ResolveBinding("y", globalenv);
	Type* e8 = assignment(e7, e6);
	// z=y
	Type* e9 = ResolveBinding("y", globalenv);
	Type* e10 = ResolveBinding("z", globalenv);
	Type* e11 = assignment(e10, e9);
}
