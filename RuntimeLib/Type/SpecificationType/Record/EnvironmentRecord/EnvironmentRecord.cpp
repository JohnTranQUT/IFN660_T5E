#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>

CompletionRecord* EnvironmentRecord::SetMutableBinding(StringType * N, LanguageType * V, BooleanType * S){
	if (S->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	//Perform Binding
	return NormalCompletion(nullptr);
}
LanguageType* EnvironmentRecord::GetBindingValue(StringType* N, BooleanType* S) {
	//The concrete Environment Record method GetBindingValue for object Environment Records returns the value of its associated binding object's property whose name is the String value of the argument identifier N. The property should already exist but if it does not the result depends upon the value of the S argument:

	//Let envRec be the object Environment Record for which the method was invoked.
	//Let bindings be the binding object for envRec.
	//Let value be ? HasProperty(bindings, N).
	//If value is false, then
	//If S is false, return the value undefined; otherwise throw a ReferenceError exception.
	//Return ? Get(bindings, N).

	auto envRec = this;
	//auto bindings = bindingObject;
	//auto value = HasProperty(binding, N);
	//if (!value->_getValue()){
	//	if (!S->_getValue())
	//		return new UndefinedType();
	//	else {
	//		puts(ReferenceError);
	//		exit(0);
	//	}
	//}
	//return Get(bindings, N);
	return new UndefinedType();
}

CompletionRecord * EnvironmentRecord::InitializeBinding(StringType * N, Type * V)
{
	//Let envRec be the declarative Environment Record for which the method was invoked.
	auto envRec = this;
	//Assert: envRec must have an uninitialized binding for N.
	//Set the bound value for N in envRec to V.
	//Record that the binding for N in envRec has been initialized.
	return NormalCompletion(new UndefinedType());
}