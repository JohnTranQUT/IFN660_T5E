#include <RuntimeLib\Type\SpecificationType\RecordType\CompletionRecordType\CompletionRecordTypeFunc.h>

CompletionRecordType* NormalCompletion(LanguageType* arguement) {
	return new CompletionRecordType("normal", arguement);
}
CompletionRecordType* NormalCompletion(string infinity) {
	if (infinity == "infinity") {
		return new CompletionRecordType("undefined", new UndefinedType());
	}
}
CompletionRecordType * ThrowAnException(){
	return nullptr;
}
Type* ReturnIfAbrupt(Type* arguement) {
	if (auto _arguement = dynamic_cast<CompletionRecordType*>(arguement)) {
		if (_arguement->AbruptCompletion()) {
			return arguement;
		}
		else {
			return _arguement->_getValue();
		}
	}
}

CompletionRecordType * UpdateEmpty(CompletionRecordType * completionRecord, LanguageType * value)
{
	if (completionRecord->_getType() == "throw" || completionRecord->_getType() == "return") {
		return completionRecord;
	}
	if (dynamic_cast<UndefinedType *>(completionRecord->_getValue()) || completionRecord->_getValue() == nullptr) {//empty test
		return new CompletionRecordType(completionRecord->_getType(), value, completionRecord->_getTarget());
	}
	return completionRecord;
}
