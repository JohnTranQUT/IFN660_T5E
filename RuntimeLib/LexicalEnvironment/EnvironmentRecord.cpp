#include "EnvironmentRecord.h"



EnvironmentRecord::EnvironmentRecord()
{
}

void EnvironmentRecord::InitializeBinding(std::string n, JSValue* v)
{
	symbol_table->insert(std::pair<std::string, JSValue*>(n, v));
}


EnvironmentRecord::~EnvironmentRecord()
{
}
