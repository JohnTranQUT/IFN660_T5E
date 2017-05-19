#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>

#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h> // for data dumping

//Making EnvironmentRecord
//This type is basically the Declaration type
class EnvironmentRecord : public Record {
public:
	explicit EnvironmentRecord() {};
	BooleanType* HasBinding(StringType* N);
	CompletionRecord* CreateMutableBinding(StringType* N, BooleanType* D);
	CompletionRecord* CreateImmutableBinding(StringType* N, BooleanType* S);
	CompletionRecord* InitializeBinding(StringType* N, Type* V);
	CompletionRecord* SetMutableBinding(StringType* N, LanguageType* V,BooleanType* S);
	LanguageType* GetBindingValue(StringType* N, BooleanType* S);
	BooleanType* DeleteBinding(StringType* N);
	BooleanType* HasThisBinding() { return new BooleanType(false); };
	BooleanType* HasSuperBinding() { return new BooleanType(false); };
	Type* WithBaseObject() { return new UndefinedType(); };
	//for testing
	void dumpEnvRecords();
};