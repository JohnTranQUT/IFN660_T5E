#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecordFunc.h>

EnvironmentRecord* NewDeclarativeEnvironmentRecord() {
	return new DeclarativeEnvironmentRecord();
}

EnvironmentRecord * NewObjectEnvironmentRecord(map<StringType*, Type*, RECORD_COMPARE> O){
	return new ObjectEnvironmentRecord(O);
}

EnvironmentRecord * NewGlobalEnvironmentRecord(EnvironmentRecord* ObjectRecord, Type* GlobalThisValue, EnvironmentRecord* DeclarativeRecord, Type* VarNames) {
	return new GlobalEnvironmentRecord(ObjectRecord, GlobalThisValue, DeclarativeRecord, VarNames);
}