#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironment.h>

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E) {
	return new LexicalEnvironment();
}