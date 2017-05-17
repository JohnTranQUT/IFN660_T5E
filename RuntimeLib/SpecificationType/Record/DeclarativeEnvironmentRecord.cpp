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
	
		symbol_table[n] = v;
}



DeclarativeEnvironmentRecord::~DeclarativeEnvironmentRecord()
{
}

void DeclarativeEnvironmentRecord::CreateMutableBinding(std::string n)
{
	//Assert: envRec does not already have a binding for N.
	if (!this->HasBinding(n))
	{
		//Create a mutable binding in envRec for N and set its bound value to undefined.
		UndefinedValue *undefined = new UndefinedValue();
		symbol_table.insert(std::pair<std::string, JSValue*>(n, undefined));
	}
}
