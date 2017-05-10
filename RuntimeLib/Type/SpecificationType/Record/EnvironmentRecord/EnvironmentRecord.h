#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\Record.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>

//Making Object EnvironmentRecord
class EnvironmentRecord : public Record {
public:
	explicit EnvironmentRecord() {};
	CompletionRecord* SetMutableBinding(StringType* N, LanguageType* V,BooleanType* S);
	LanguageType* GetBindingValue(StringType* N, BooleanType* S);
	//BooleanType* HasBinding(StringType* N);
	//BooleanType* CreateMutableBinding(StringType* N, BooleanType* D);
	//BooleanType* InitializeBinding();
};