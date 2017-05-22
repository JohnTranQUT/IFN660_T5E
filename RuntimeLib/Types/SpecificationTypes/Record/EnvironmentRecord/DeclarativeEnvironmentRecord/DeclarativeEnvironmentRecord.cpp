#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h"

BooleanType *DeclarativeEnvironmentRecord::HasBinding(StringType *N) {
	return EnvironmentRecord::HasBinding(N);
}

CompletionRecord *DeclarativeEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *D) {
	EnvironmentRecord::CreateMutableBinding(N, D);
	return NormalCompletion(nullptr);
}

CompletionRecord *DeclarativeEnvironmentRecord::CreateImmutableBinding(StringType *N, BooleanType *S) {
	EnvironmentRecord::CreateMutableBinding(N, S);
	return NormalCompletion(nullptr);
}

CompletionRecord *DeclarativeEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	EnvironmentRecord::InitializeBinding(N, V);
	return NormalCompletion(nullptr);
}

CompletionRecord *DeclarativeEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
	if (!_hasValue(N)->_getValue()) {
		if (S->_getValue()) {
			puts("ReferenceError");
			exit(0);
		}
		EnvironmentRecord::CreateMutableBinding(N, new BooleanType(true));
		EnvironmentRecord::InitializeBinding(N, V);
		return NormalCompletion(nullptr);
	}
	if (!_hasInitialized(N)->_getValue()) {
		puts("ReferenceError");
		exit(0);
	}
	EnvironmentRecord::SetMutableBinding(N, V, S);
	return NormalCompletion(nullptr);
}

Type *DeclarativeEnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
	return EnvironmentRecord::GetBindingValue(N, S);
}

BooleanType *DeclarativeEnvironmentRecord::DeleteBinding(StringType *N) {
	return EnvironmentRecord::DeleteBinding(N);
}

BooleanType *DeclarativeEnvironmentRecord::HasThisBinding() {
	return new BooleanType(false);
}

BooleanType *DeclarativeEnvironmentRecord::HasSuperBinding() {
	return new BooleanType(false);
}

LanguageType *DeclarativeEnvironmentRecord::WithBaseObject() {
	return new UndefinedType();
}
