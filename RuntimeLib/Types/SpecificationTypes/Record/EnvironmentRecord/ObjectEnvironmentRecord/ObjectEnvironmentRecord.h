#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h"

class ObjectEnvironmentRecord : public EnvironmentRecord {
	ObjectType *bindingObject;
	BooleanType *WithEnvironment;
public:
	explicit ObjectEnvironmentRecord(
		ObjectType *_bindingObject,
		BooleanType *_WithEnvironment = new BooleanType(false)
	) : bindingObject(_bindingObject),
	    WithEnvironment(_WithEnvironment) { }

	BooleanType *HasBinding(StringType *) override;
	CompletionRecord *CreateMutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *CreateImmutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *InitializeBinding(StringType *, LanguageType *) override;
	CompletionRecord *SetMutableBinding(StringType *, LanguageType *, BooleanType *) override;
	Type *GetBindingValue(StringType *, BooleanType *) override;
	BooleanType *DeleteBinding(StringType *) override;
	BooleanType *HasThisBinding() override;
	BooleanType *HasSuperBinding() override;
	Type *WithBaseObject() override;
};
