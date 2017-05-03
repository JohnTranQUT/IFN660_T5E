#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "RuntimeLib/SpecificationType/SpecificationType.h"

class Record: public SpecificationType {
protected:
	std::map<std::string, JSValue*> symbol_table;
};




