#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>

EnvironmentRecord *LexicalEnvironment::_getEnvRec() const {
	return environmentRecord;
}

LexicalEnvironment *LexicalEnvironment::_getOuter() const {
	return outer;
}
