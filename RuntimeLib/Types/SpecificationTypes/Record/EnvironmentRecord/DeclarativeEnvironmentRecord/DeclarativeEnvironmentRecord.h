#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>

class DeclarativeEnvironmentRecord : public EnvironmentRecord {
public:
	DeclarativeEnvironmentRecord() { }
	BooleanType *HasBinding(StringType *) override;
	CompletionRecord *CreateMutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *CreateImmutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *InitializeBinding(StringType *, LanguageType *) override;
	CompletionRecord *SetMutableBinding(StringType *, LanguageType *, BooleanType *) override;
	Type *GetBindingValue(StringType *, BooleanType *) override;
	BooleanType *DeleteBinding(StringType *) override;
	BooleanType *HasThisBinding() override;
	BooleanType *HasSuperBinding() override;
	LanguageType *WithBaseObject() override;
};
