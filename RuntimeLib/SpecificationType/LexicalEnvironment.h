#pragma once
#include "RuntimeLib/LexicalEnvironment/EnvironmentRecord.h"

class LexicalEnvironment
{
private:
	EnvironmentRecord *environmentRecord;
	LexicalEnvironment *outer;
public:
	explicit LexicalEnvironment(EnvironmentRecord *environmentRecord);
	~LexicalEnvironment();
};

