#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Record/Record.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"

class EnvironmentRecord : public Record {
public:
	EnvironmentRecord() { }
	virtual BooleanType *HasBinding(StringType *);
	virtual CompletionRecord *CreateMutableBinding(StringType *, BooleanType *);
	virtual CompletionRecord *CreateImmutableBinding(StringType *, BooleanType *);
	virtual CompletionRecord *InitializeBinding(StringType *, LanguageType *);
	virtual CompletionRecord *SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	virtual Type *GetBindingValue(StringType *, BooleanType *);
	virtual BooleanType *DeleteBinding(StringType *);
	virtual BooleanType *HasThisBinding();
	virtual BooleanType *HasSuperBinding();
	virtual Type *WithBaseObject();
};
