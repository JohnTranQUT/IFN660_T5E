#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\DeclarativeEnvironmentRecord\DeclarativeEnvironmentRecord.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\ObjectEnvironmentRecord\ObjectEnvironmentRecord.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\GlobalEnvironmentRecord\GlobalEnvironmentRecord.h>

EnvironmentRecord* NewDeclarativeEnvironmentRecord();
EnvironmentRecord* NewObjectEnvironmentRecord(map<StringType*,Type*,RECORD_COMPARE> O);
EnvironmentRecord* NewGlobalEnvironmentRecord(EnvironmentRecord* ObjectRecord, Type* GlobalThisValue, EnvironmentRecord* DeclarativeRecord, Type* VarNames=nullptr);