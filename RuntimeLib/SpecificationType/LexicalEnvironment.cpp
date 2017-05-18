#include "LexicalEnvironment.h"


LexicalEnvironment::LexicalEnvironment(EnvironmentRecord* environmentRecord):envRec(environmentRecord)
{
	outer = nullptr;
}

