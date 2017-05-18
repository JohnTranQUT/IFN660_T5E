#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>


class LexicalEnvironment : public SpecificationType {
	LexicalEnvironment* _outer;
	EnvironmentRecord* env;
public :
	LexicalEnvironment(LexicalEnvironment* outer = nullptr): _outer(outer) {};
};

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E);
//LexicalEnvironment* NewObjectEnvironment(BindingObject* O, LexicalEnvironment* E);
//LexicalEnvironment* NewGlobalEnvironment(G, thisValue);
