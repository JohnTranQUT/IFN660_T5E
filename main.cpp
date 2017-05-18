#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <typeinfo>
#include "Operators/operator.h"
//#include "parser.h"

//extern FILE *yyin;
using namespace std;


void main(int argc, char *argv[]) {
	//fopen_s(&yyin, "test.js", "r");
	//yyparse();
	LexicalEnvironment* simGlobalEnvironment = new LexicalEnvironment();
	simGlobalEnvironment->SetEnvironment(new DeclarativeEnvironmentRecord());
	simGlobalEnvironment->GetEnvironment()->CreateMutableBinding("x",false);
	Reference* ref_x = dynamic_cast<Reference*>(ResolveBinding("x", simGlobalEnvironment));
	ref_x->SetBase(new Number(42));
	
	//
	String* obj = new String("test");
	if ((dynamic_cast<Type*>(obj))) printf("hello") ;
}
