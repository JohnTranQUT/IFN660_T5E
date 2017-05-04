#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
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
};
