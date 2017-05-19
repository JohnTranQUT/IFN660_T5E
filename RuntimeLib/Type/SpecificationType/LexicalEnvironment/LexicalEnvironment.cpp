#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironment.h>

EnvironmentRecord* LexicalEnvironment::getEnvRec(){
	return _envRec;
}

LexicalEnvironment* LexicalEnvironment::getOuter(){
	return _outer;
}
