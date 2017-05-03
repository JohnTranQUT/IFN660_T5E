#pragma once
#include "RuntimeLib/SpecificationType/EnvironmentRecord.h"

class DeclarativeEnvironmentRecord :public EnvironmentRecord
{
public:
	DeclarativeEnvironmentRecord();
	bool HasBinding(std::string n) override;
	JSValue* GetBindingValue(std::string n) override;
	void setMutableBinding(std::string n, JSValue *v) override;
	void InitializeBinding(std::string n, JSValue *v) override;
	~DeclarativeEnvironmentRecord();
};

