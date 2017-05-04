#pragma once
#include "js_type.h"
#include "Record.h"

class EnvironmentRecord: public Record {
public:
	virtual bool HasBinding(string n) = 0;
	virtual GeneralType* GetBindingValue(string n)=0;
	virtual void SetMutableBinding(string n, GeneralType* v) =0;
	virtual void InitializeBinding(string n, GeneralType *v) =0;
};

