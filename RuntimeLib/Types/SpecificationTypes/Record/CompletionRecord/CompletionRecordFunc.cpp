#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h"

Type *ReturnIfAbrupt(CompletionRecord *argument) {
	auto _Type = dynamic_cast<StringType *>(argument->_findValue(new StringType("Type")))->_getValue();
	if (_Type == "break" || _Type == "continue" || _Type == "return" || _Type == "throw") {
		return argument;
	} else {
		return argument->_findValue(new StringType("Value"));
	}
}

CompletionRecord *NormalCompletion(LanguageType *argument) {
	return new CompletionRecord(new StringType("normal"), argument, nullptr);
}
