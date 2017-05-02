#include <Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>

BooleanType *DeclarativeEnvironmentRecord::HasBinding(StringType *N) {
	return EnvironmentRecord::HasBinding(N);
}

CompletionType *DeclarativeEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *D) {
	EnvironmentRecord::CreateMutableBinding(N, D);
	return NormalCompletion(nullptr);
}

CompletionType *DeclarativeEnvironmentRecord::CreateImmutableBinding(StringType *N, BooleanType *S) {
	EnvironmentRecord::CreateMutableBinding(N, S);
	return NormalCompletion(nullptr);
}

CompletionType *DeclarativeEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	EnvironmentRecord::InitializeBinding(N, V);
	return NormalCompletion(nullptr);
}

CompletionType *DeclarativeEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
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

LanguageType *DeclarativeEnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
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
