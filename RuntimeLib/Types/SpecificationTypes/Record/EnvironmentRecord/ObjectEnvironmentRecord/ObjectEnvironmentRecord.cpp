#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"

BooleanType *ObjectEnvironmentRecord::HasBinding(StringType *N) {
	auto bindings = bindingObject;
	auto foundBinding = bindings->_hasProperty(N);
	return foundBinding;
}

CompletionRecord *ObjectEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *) {
	auto bindings = bindingObject;
	return bindingObject->Set(N, new UndefinedType());
}

CompletionRecord *ObjectEnvironmentRecord::CreateImmutableBinding(StringType *, BooleanType *) {
	return nullptr;
}

CompletionRecord *ObjectEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	SetMutableBinding(N, V, new BooleanType(false));
	return nullptr;
}

CompletionRecord *ObjectEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
	auto bindings = bindingObject;
	return bindingObject->Set(N, V);
}

Type *ObjectEnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
	auto bindings = bindingObject;
	auto value = bindings->_hasProperty(N);
	if (!value->_getValue()) {
		if (!S->_getValue()) {
			return new UndefinedType();
		}
		puts("ReferenceError");
		exit(0);
	}
	return bindings->Get(N);
}

BooleanType *ObjectEnvironmentRecord::DeleteBinding(StringType *N) {
	auto bindings = bindingObject;
	return bindings->Delete(N);
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
