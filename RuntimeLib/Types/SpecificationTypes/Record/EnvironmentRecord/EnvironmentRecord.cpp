#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>

BooleanType *EnvironmentRecord::HasBinding(StringType *N) {
	return _hasValue(N);
}

CompletionRecord *EnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *S) {
	_insertValue(N, nullptr);
	return nullptr;
}

CompletionRecord *EnvironmentRecord::CreateImmutableBinding(StringType *N, BooleanType *S) {
	_insertValue(N, nullptr);
	return nullptr;
}

CompletionRecord *EnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	_setValue(N, V);
	return nullptr;
}

CompletionRecord *EnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
	if (S->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	_setValue(N, V);
	return nullptr;
}

Type *EnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
	if (S->_getValue()) {
		if (!_hasValue(N)->_getValue()) {
			puts("ReferenceError");
			exit(0);
		}
	}
	if (!_hasInitialized(N)->_getValue()) {
		puts("ReferenceError");
		exit(0);
	}
	return _findValue(N);
}

BooleanType *EnvironmentRecord::DeleteBinding(StringType *N) {
	return _deleteValue(N);
}

BooleanType *EnvironmentRecord::HasThisBinding() {
	return _hasValue(new StringType("this"));
}

BooleanType *EnvironmentRecord::HasSuperBinding() {
	return _hasValue(new StringType("super"));
}

Type *EnvironmentRecord::WithBaseObject() {
	// withObject
	return _findValue(new StringType("with"));
}
