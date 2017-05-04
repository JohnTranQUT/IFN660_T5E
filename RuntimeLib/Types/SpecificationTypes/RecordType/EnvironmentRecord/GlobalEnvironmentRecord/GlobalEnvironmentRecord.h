#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/ListType/ListType.h>

class GlobalEnvironmentRecord : public EnvironmentRecord {
public:
	GlobalEnvironmentRecord(
		ObjectEnvironmentRecord *,
		ObjectType *,
		DeclarativeEnvironmentRecord *,
		ListType * = new ListType()
	);

};
