#pragma once
#include "SpecificationType.h"
#include "Record/EnvironmentRecord.h"

class LexicalEnvironment:public SpecificationType {
public:
	EnvironmentRecord *envRec;
	LexicalEnvironment *outer;
	explicit LexicalEnvironment(EnvironmentRecord *envRec):envRec(envRec) ,outer(nullptr){}
	virtual ~LexicalEnvironment(){};
};

