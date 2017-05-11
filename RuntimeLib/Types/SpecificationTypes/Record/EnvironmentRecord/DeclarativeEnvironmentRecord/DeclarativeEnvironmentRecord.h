#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h>

class DeclarativeEnvironmentRecord : public EnvironmentRecord {
public:
	DeclarativeEnvironmentRecord() { }
	BooleanType *HasBinding(StringType *);
	CompletionRecord *CreateMutableBinding(StringType *, BooleanType *);
	CompletionRecord *CreateImmutableBinding(StringType *, BooleanType *);
	CompletionRecord *InitializeBinding(StringType *, LanguageType *);
	CompletionRecord *SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	Type *GetBindingValue(StringType *, BooleanType *);
	BooleanType *DeleteBinding(StringType *);
	static BooleanType *HasThisBinding();
	static BooleanType *HasSuperBinding();
	static LanguageType *WithBaseObject();
};
