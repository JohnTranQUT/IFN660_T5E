#pragma once
#include "js_type.h"

class Record: public SpecificationType {
protected:
	map<string, GeneralType*> symbol_table;
};




