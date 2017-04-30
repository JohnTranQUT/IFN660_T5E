#include <Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>

Type *ReturnIfAbrupt(CompletionType *argument) {
	auto _Type = argument->_getType();
	if (_Type == "break" || _Type == "continue" || _Type == "return" || _Type == "throw") {
		return argument;
	} else {
		return argument->_getValue();
	}
}

CompletionType *NormalCompletion(LanguageType *argument) {
	return new CompletionType("normal", argument, nullptr);
}
