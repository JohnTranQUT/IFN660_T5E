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
