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

	//Perform Binding
	return new UndefinedType();
}

CompletionRecord * EnvironmentRecord::InitializeBinding(StringType * N, Type * V)
{
	//Let envRec be the declarative Environment Record for which the method was invoked.
	auto envRec = new EnvironmentRecord();
	//Assert: envRec must have an uninitialized binding for N.
	//Set the bound value for N in envRec to V.
	//Record that the binding for N in envRec has been initialized.
	return NormalCompletion(new UndefinedType());
}
