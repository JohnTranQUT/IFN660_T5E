#include "LexicalEnvironment.h"


LexicalEnvironment::LexicalEnvironment(EnvironmentRecord* environmentRecord):environmentRecord(environmentRecord)
{
	outer = nullptr;
}

LexicalEnvironment::~LexicalEnvironment()
{
}
