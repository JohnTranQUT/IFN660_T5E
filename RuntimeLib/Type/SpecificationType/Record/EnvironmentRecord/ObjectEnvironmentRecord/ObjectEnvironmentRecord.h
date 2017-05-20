#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>

class ObjectEnvironmentRecord : public EnvironmentRecord {
public:
	explicit ObjectEnvironmentRecord(map<StringType*, Type*, RECORD_COMPARE> O) { Record::_setBinding(O);}
};
