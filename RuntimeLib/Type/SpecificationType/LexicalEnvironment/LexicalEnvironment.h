#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>


class LexicalEnvironment : public SpecificationType {

public :
	LexicalEnvironment() {};
};

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E);
//LexicalEnvironment* NewObjectEnvironment(BindingObject* O, LexicalEnvironment* E);
//LexicalEnvironment* NewGlobalEnvironment(G, thisValue);
