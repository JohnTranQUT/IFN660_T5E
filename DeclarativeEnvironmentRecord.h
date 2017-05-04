#pragma once
#include "js_type.h"
#include "EnvironmentRecord.h"

class DeclarativeEnvironmentRecord :public EnvironmentRecord
{
public:
	DeclarativeEnvironmentRecord();
	bool HasBinding(string n) override;
	GeneralType* GetBindingValue(string n) override;
	void InitializeBinding(string n, GeneralType *v) override;
	void SetMutableBinding(string n, GeneralType* v) override;
	~DeclarativeEnvironmentRecord();
};

