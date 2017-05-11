#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/Record.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>

class EnvironmentRecord : public Record {
public:
	EnvironmentRecord() { }
	BooleanType *HasBinding(StringType *);
	void CreateMutableBinding(StringType *, BooleanType *);
	void CreateImmutableBinding(StringType *, BooleanType *);
	void InitializeBinding(StringType *, LanguageType *);
	void SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	Type *GetBindingValue(StringType *, BooleanType *);
	BooleanType *DeleteBinding(StringType *);
	BooleanType *HasThisBinding();
	BooleanType *HasSuperBinding();
	Type *WithBaseObject();
};
