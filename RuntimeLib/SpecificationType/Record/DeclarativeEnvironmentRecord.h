#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "EnvironmentRecord.h"

class DeclarativeEnvironmentRecord :public EnvironmentRecord
{
public:
	DeclarativeEnvironmentRecord();
	bool HasBinding(std::string n) override;
	JSValue* GetBindingValue(std::string n) override;
	void InitializeBinding(std::string n, JSValue *v) override;
	void SetMutableBinding(std::string n, JSValue* v) override;
	~DeclarativeEnvironmentRecord();
};

