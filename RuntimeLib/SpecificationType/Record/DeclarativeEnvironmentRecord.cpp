#include "DeclarativeEnvironmentRecord.h"



DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord()
{
}

bool DeclarativeEnvironmentRecord::HasBinding(std::string n)
{
	std::map<std::string, JSValue*>::iterator iter = symbol_table.find(n);
	if (iter!=symbol_table.end())
	{
		return true;
	}
	else return false;

}

JSValue* DeclarativeEnvironmentRecord::GetBindingValue(std::string n)
{
	std::map<std::string, JSValue*>::iterator iter = symbol_table.find(n);
	if (iter != symbol_table.end())
	{
		return iter->second;
	}
	else return nullptr;
}

void DeclarativeEnvironmentRecord::SetMutableBinding(std::string n, JSValue* v)
{
	symbol_table.insert(std::pair<std::string, JSValue*>(n, v));
}

void DeclarativeEnvironmentRecord::InitializeBinding(std::string n, JSValue* v)
{
	symbol_table.insert(std::pair<std::string, JSValue*>(n, v));
}


DeclarativeEnvironmentRecord::~DeclarativeEnvironmentRecord()
{
}
