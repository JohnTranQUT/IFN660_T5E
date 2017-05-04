#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>

class ObjectEnvironmentRecord : public EnvironmentRecord {
	ObjectType *bindingObject;
public:
	explicit ObjectEnvironmentRecord(ObjectType *_bindingObject) : bindingObject(_bindingObject) { }
};
