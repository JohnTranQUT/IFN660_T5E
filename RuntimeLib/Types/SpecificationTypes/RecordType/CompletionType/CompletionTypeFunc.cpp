#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>

Type *ReturnIfAbrupt(CompletionType *argument) {
	auto _Type = dynamic_cast<StringType *>(argument->_findValue(new StringType("Type")))->_getValue();
	if (_Type == "break" || _Type == "continue" || _Type == "return" || _Type == "throw") {
		return argument;
	} else {
		return argument->_findValue(new StringType("Value"));
	}
}

CompletionType *NormalCompletion(LanguageType *argument) {
	return new CompletionType(new StringType("normal"), argument, nullptr);
}
