#pragma once
#include "EnvironmentRecord.h"

class LexicalEnvironment
{
private:
	EnvironmentRecord *environmentRecord;
	LexicalEnvironment *outer;
public:
	explicit LexicalEnvironment(EnvironmentRecord* environmentRecord) :environmentRecord(environmentRecord)
	{
		outer = nullptr;
	}
	~LexicalEnvironment() {}
};

