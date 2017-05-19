#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecordFunc.h>

EnvironmentRecord* NewDeclarativeEnvironmentRecord() {
	return new DeclarativeEnvironmentRecord();
}