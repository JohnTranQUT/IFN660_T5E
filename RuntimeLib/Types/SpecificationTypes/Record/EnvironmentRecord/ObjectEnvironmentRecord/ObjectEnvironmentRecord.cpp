#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"

BooleanType *ObjectEnvironmentRecord::HasBinding(StringType *N) {
	puts("ObjectEnvironmentRecord::HasBinding()");
	exit(0);
}

CompletionRecord *ObjectEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *D) {
	BooleanType *configValue;
	if (D->_getValue()) {
		configValue = new BooleanType(true);
	} else {
		configValue = new BooleanType(false);
	}
	puts("Return ? DefinePropertyOrThrow(bindings, N, PropertyDescriptor{[[Value]]: undefined, [[Writable]]: true, [[Enumerable]]: true, [[Configurable]]: configValue})");
	exit(0);
}

CompletionRecord *ObjectEnvironmentRecord::CreateImmutableBinding(StringType *, BooleanType *) {
	return nullptr;
}

CompletionRecord *ObjectEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	SetMutableBinding(N, V, new BooleanType(false));
	return nullptr;
}

CompletionRecord *ObjectEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
	puts("Return ? Set(bindings, N, V, S)");
	exit(0);
}

Type *ObjectEnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
	puts("ObjectEnvironmentRecord::GetBindingValue()");
	exit(0);
}

BooleanType *ObjectEnvironmentRecord::DeleteBinding(StringType *N) {
	puts("Return ? bindings.[[Delete]](N)");
	exit(0);
}

BooleanType *ObjectEnvironmentRecord::HasThisBinding() {
	return new BooleanType(false);
}

BooleanType *ObjectEnvironmentRecord::HasSuperBinding() {
	return new BooleanType(false);
}

Type *ObjectEnvironmentRecord::WithBaseObject() {
	if (WithEnvironment->_getValue()) {
		return bindingObject;
	}
	return new UndefinedType();
}
