#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>


CompletionRecord* EnvironmentRecord::SetMutableBinding(StringType* N, LanguageType* V, BooleanType* S){
	if (S->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	//Perform Binding
	auto envRec = this;
	_setValue(N, V);
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

	//auto envRec = this;
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
	if (!_hasValue(N)->_getValue()) {
		if (!S->_getValue())
			return new UndefinedType();
		else {
			puts("ReferenceError");
			exit(0);
		}
	}

	return dynamic_cast<LanguageType*>(_getValue2(N));
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

BooleanType* EnvironmentRecord::HasBinding(StringType* N) {
	return _hasValue(N);
}

//for testing
void EnvironmentRecord::dumpEnvRecords() {
	auto temp = _getValue();
	map<StringType*, Type*, RECORD_COMPARE>::iterator it;
	for (it = temp.begin(); it != temp.end(); it++)
	{
		puts(it->first->_getValue().c_str());
		if (auto _temp = dynamic_cast<NumberType *>(it->second))
			puts(to_string(_temp->_getValue()).c_str());
		if (auto _temp = dynamic_cast<StringType *>(it->second))
			puts(_temp->_getValue().c_str());
	}
}