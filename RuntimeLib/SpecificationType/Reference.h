#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "RuntimeLib/JSValue/Operator.h"
#include "RuntimeLib/Type.h"

class Reference: public Type
{
private :
	JSValue* base;
	std::string name;
	bool strictReference;
public:
	Reference(JSValue* base, std::string name);
	JSValue* GetBase();
	std::string GetReferenceName();
	bool isStrictReference();
	bool isUnresolvableReference();
	~Reference();
};

