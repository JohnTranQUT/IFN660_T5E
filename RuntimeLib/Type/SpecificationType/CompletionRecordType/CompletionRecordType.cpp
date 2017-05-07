#include <RuntimeLib\Type\SpecificationType\CompletionRecordType\CompletionRecordType.h>

bool CompletionRecordType::AbruptCompletion() {
	if (_type != "Normal")
		return true;
	return false;
}


string CompletionRecordType::_getType() {
	return _type;
}

LanguageType* CompletionRecordType::_getValue(){
	return Value;
}

LanguageType* CompletionRecordType::_getTarget() {
	return Target;
}
