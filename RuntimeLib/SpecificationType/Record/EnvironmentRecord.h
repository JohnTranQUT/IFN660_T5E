#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "Record.h"

class EnvironmentRecord: public Record {
public:
	virtual bool HasBinding(std::string n) = 0;
	virtual JSValue* GetBindingValue(std::string n)=0;
	virtual void SetMutableBinding(std::string n, JSValue* v) =0;
	virtual void InitializeBinding(std::string n, JSValue *v)=0;
};

