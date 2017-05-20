#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>

#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h> // for data dumping

//Making EnvironmentRecord
//This type is basically the Declaration type
class EnvironmentRecord : public Record {
public:
	explicit EnvironmentRecord() {};
	virtual BooleanType* HasBinding(StringType* N);
	virtual CompletionRecord* CreateMutableBinding(StringType* N, BooleanType* D);
	virtual CompletionRecord* CreateImmutableBinding(StringType* N, BooleanType* S);
	virtual CompletionRecord* InitializeBinding(StringType* N, Type* V);
	virtual CompletionRecord* SetMutableBinding(StringType* N, LanguageType* V,BooleanType* S);
	virtual LanguageType* GetBindingValue(StringType* N, BooleanType* S);
	virtual BooleanType* DeleteBinding(StringType* N);
	virtual BooleanType* HasThisBinding() { return new BooleanType(false); };
	virtual BooleanType* HasSuperBinding() { return new BooleanType(false); };
	virtual Type* WithBaseObject() { return new UndefinedType(); };
	//for testing
	virtual void dumpEnvRecords();
};