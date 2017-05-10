#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>

BooleanType* EnvironmentRecord::SetMutableBinding(StringType * N, LanguageType * V, BooleanType * S){
	if (S->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	//Perform Binding
	return new BooleanType(true);
}
