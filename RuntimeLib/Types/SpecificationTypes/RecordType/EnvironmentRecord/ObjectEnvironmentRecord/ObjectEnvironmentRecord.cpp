#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>

BooleanType *ObjectEnvironmentRecord::HasBinding(StringType *N) {
	puts("ObjectEnvironmentRecord::HasBinding()");
	exit(0);
}

void ObjectEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *D) {
	BooleanType *configValue;
	if (D->_getValue()) {
		configValue = new BooleanType(true);
	} else {
		configValue = new BooleanType(false);
	}
	puts("Return ? DefinePropertyOrThrow(bindings, N, PropertyDescriptor{[[Value]]: undefined, [[Writable]]: true, [[Enumerable]]: true, [[Configurable]]: configValue})");
	exit(0);
}

void ObjectEnvironmentRecord::CreateImmutableBinding(StringType *, BooleanType *) { }

void ObjectEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	SetMutableBinding(N, V, new BooleanType(false));
}

void ObjectEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
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

Type *ObjectEnvironmentRecord::WithBaseObject() const {
	if (WithEnvironment->_getValue()) {
		return bindingObject;
	}
	return new UndefinedType();
}
