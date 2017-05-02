#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

GlobalEnvironmentRecord::GlobalEnvironmentRecord(ObjectEnvironmentRecord *ObjectRecord, ObjectType *GlobalThisValue, DeclarativeEnvironmentRecord *DeclarativeRecord, ListType *VarNames) {
	_insertValue(new StringType("ObjectRecord"), ObjectRecord);
	_insertValue(new StringType("GlobalThisValue"), GlobalThisValue);
	_insertValue(new StringType("DeclarativeRecord"), DeclarativeRecord);
	_insertValue(new StringType("VarNames"), VarNames);
}
