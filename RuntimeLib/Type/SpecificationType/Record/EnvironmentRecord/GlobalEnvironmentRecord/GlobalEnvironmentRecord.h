#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\ObjectEnvironmentRecord\ObjectEnvironmentRecord.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\DeclarativeEnvironmentRecord\DeclarativeEnvironmentRecord.h>

class GlobalEnvironmentRecord : public EnvironmentRecord {
	ObjectEnvironmentRecord* _ObjectRecord;
	DeclarativeEnvironmentRecord* _DeclarativeRecord;
	Type* _GlobalThisValue;
public:
	explicit GlobalEnvironmentRecord(EnvironmentRecord* ObjectRecord, Type* GlobalThisValue, EnvironmentRecord* DeclarativeRecord, Type* VarNames)
	: _ObjectRecord(dynamic_cast<ObjectEnvironmentRecord*>(ObjectRecord)),
		_DeclarativeRecord(dynamic_cast<DeclarativeEnvironmentRecord*>(DeclarativeRecord)),
		_GlobalThisValue(GlobalThisValue)
	{}
};