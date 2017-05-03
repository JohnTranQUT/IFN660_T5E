#pragma once
#include "RuntimeLib/JSValue/JSValue.h"

class EnvironmentRecord
{
protected:
	std::map<std::string, JSValue*> symbol_table;
public:
	EnvironmentRecord();
	virtual bool HasBinding(std::string n) = 0;
	virtual JSValue* GetBindingValue(std::string n);
	virtual void InitializeBinding(std::string n, JSValue *v)=0;
	virtual ~EnvironmentRecord();
};

