#pragma once
#include <Types/SpecificationTypes/RecordType/RecordType.h>
#include <Types/LanguageTypes/BooleanType/BooleanType.h>

class EnvironmentRecord : public RecordType {
public:
	EnvironmentRecord() { }
	BooleanType *HasBinding(StringType *);
	void CreateMutableBinding(StringType *, BooleanType *);
	void CreateImmutableBinding(StringType *, BooleanType *);
	void InitializedBinding(StringType *, LanguageType *);
	void SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	LanguageType *GetBindingValue(StringType *, BooleanType *);
	BooleanType *DeleteBinding(StringType *);
	BooleanType *HasThisBinding();
	BooleanType *HasSuperBinding();
	LanguageType *WithBaseObject();
};
