#include "Record.h"

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord()
{
}

bool DeclarativeEnvironmentRecord::HasBinding(string n)
{
	map<string, Type*>::iterator iter = symbol_table.find(n);
	if (iter!=symbol_table.end())
	{
		return true;
	}
	else return false;

}

Type* DeclarativeEnvironmentRecord::GetBindingValue(string n)
{
	map<string, Type*>::iterator iter = symbol_table.find(n);
	if (iter != symbol_table.end())
	{
		return iter->second;
	}
	else return nullptr;
}

void DeclarativeEnvironmentRecord::SetMutableBinding(string n, Type* v)
{
	symbol_table.insert(pair<string, Type*>(n, v));
}

void DeclarativeEnvironmentRecord::InitializeBinding(string n, Type* v)
{
	symbol_table.insert(pair<string, Type*>(n, v));
}

void DeclarativeEnvironmentRecord::CreateMutableBinding(string N, bool D) {

}