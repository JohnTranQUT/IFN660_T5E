#include <Types/SpecificationTypes/RecordType/CompletionType/CompletionType.h>

string CompletionType::_getType() const {
	return Type;
}

LanguageType *CompletionType::_getValue() const {
	return Value;
}

string CompletionType::_getTarget() const {
	return Target;
}
