#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecord.h>

bool CompletionRecord::AbruptCompletion() {
	if (_type != "Normal")
		return true;
	return false;
}

string CompletionRecord::_getType() {
	return _type;
}

LanguageType* CompletionRecord::_getValue(){
	return Value;
}

LanguageType* CompletionRecord::_getTarget() {
	return Target;
}
