#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>

CompletionRecord* NormalCompletion(LanguageType* arguement) {
	return new CompletionRecord("normal", arguement);
}
CompletionRecord* NormalCompletion(string infinity) {
	if (infinity == "infinity") {
		return new CompletionRecord("undefined", new UndefinedType());
	}
}
CompletionRecord * ThrowAnException(){
	return nullptr;
}
Type* ReturnIfAbrupt(Type* arguement) {
	if (auto _arguement = dynamic_cast<CompletionRecord*>(arguement)) {
		if (_arguement->AbruptCompletion()) {
			return arguement;
		}
		else {
			return _arguement->_getValue();
		}
	}
}

CompletionRecord * UpdateEmpty(CompletionRecord * completionRecord, LanguageType * value)
{
	if (completionRecord->_getType() == "throw" || completionRecord->_getType() == "return") {
		return completionRecord;
	}
	if (dynamic_cast<UndefinedType *>(completionRecord->_getValue()) || completionRecord->_getValue() == nullptr) {//empty test
		return new CompletionRecord(completionRecord->_getType(), value, completionRecord->_getTarget());
	}
	return completionRecord;
}
