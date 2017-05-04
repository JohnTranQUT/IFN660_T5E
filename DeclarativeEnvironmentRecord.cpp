#include "DeclarativeEnvironmentRecord.h"



DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord()
{
}

bool DeclarativeEnvironmentRecord::HasBinding(string n)
{
	map<string, GeneralType*>::iterator iter = symbol_table.find(n);
	if (iter!=symbol_table.end())
	{
		return true;
	}
	else return false;

}

GeneralType* DeclarativeEnvironmentRecord::GetBindingValue(string n)
{
	map<string, GeneralType*>::iterator iter = symbol_table.find(n);
	if (iter != symbol_table.end())
	{
		return iter->second;
	}
	else return nullptr;
}

void DeclarativeEnvironmentRecord::SetMutableBinding(string n, GeneralType* v)
{
	symbol_table.insert(pair<string, GeneralType*>(n, v));
}

void DeclarativeEnvironmentRecord::InitializeBinding(string n, GeneralType* v)
{
	symbol_table.insert(pair<string, GeneralType*>(n, v));
}


DeclarativeEnvironmentRecord::~DeclarativeEnvironmentRecord()
{
}
