#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\Record.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>

//Making Object EnvironmentRecord
class EnvironmentRecord : public Record {
public:
	explicit EnvironmentRecord() {};
	BooleanType* SetMutableBinding(StringType* N, LanguageType* V,BooleanType* S);
	//BooleanType* HasBinding(StringType* N);
	//BooleanType* CreateMutableBinding(StringType* N, BooleanType* D);
	//BooleanType* InitializeBinding();
};