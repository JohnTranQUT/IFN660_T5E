#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>

class DeclarativeEnvironmentRecord : public EnvironmentRecord {
public:
	DeclarativeEnvironmentRecord() { }
	BooleanType *HasBinding(StringType *);
	CompletionType *CreateMutableBinding(StringType *, BooleanType *);
	CompletionType *CreateImmutableBinding(StringType *, BooleanType *);
	CompletionType *InitializeBinding(StringType *, LanguageType *);
	CompletionType *SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	Type *GetBindingValue(StringType *, BooleanType *);
	BooleanType *DeleteBinding(StringType *);
	static BooleanType *HasThisBinding();
	static BooleanType *HasSuperBinding();
	static LanguageType *WithBaseObject();
};