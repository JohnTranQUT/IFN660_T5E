#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>

class ObjectEnvironmentRecord : public EnvironmentRecord {
	ObjectType *bindingObject;
	BooleanType *WithEnvironment;
public:
	explicit ObjectEnvironmentRecord(
		ObjectType *_bindingObject,
		BooleanType *_WithEnvironment = new BooleanType(false)
	) : bindingObject(_bindingObject),
	    WithEnvironment(_WithEnvironment) { }

	static BooleanType *HasBinding(StringType *);
	static void CreateMutableBinding(StringType *, BooleanType *);
	static void CreateImmutableBinding(StringType *, BooleanType *);
	static void InitializeBinding(StringType *, LanguageType *);
	static void SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	static Type *GetBindingValue(StringType *, BooleanType *);
	static BooleanType *DeleteBinding(StringType *);
	static BooleanType *HasThisBinding();
	static BooleanType *HasSuperBinding();
	Type *WithBaseObject() const;
};
