#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>


class LexicalEnvironment : public SpecificationType {
	LexicalEnvironment* _outer;
	EnvironmentRecord* _envRec;
public :
	LexicalEnvironment(EnvironmentRecord* envRec, LexicalEnvironment* outer) : _envRec(envRec), _outer(outer) {};
	EnvironmentRecord* getEnvRec();
	LexicalEnvironment* getOuter();
};


//LexicalEnvironment* NewObjectEnvironment(BindingObject* O, LexicalEnvironment* E);
//LexicalEnvironment* NewGlobalEnvironment(G, thisValue);
