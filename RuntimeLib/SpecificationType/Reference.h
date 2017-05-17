#pragma once
#include "RuntimeLib/Type.h"
#include <string>

class Reference: public Type
{
private :
	//base is either undefined, an Object, a Boolean, a String
	//a Symbol, a Number, or an Environment Record
	Type* base;
	std::string name;
	bool strictReference;
public:
	Reference(Type* base, std::string name);
	Type* GetBase();
	std::string GetReferenceName();
	bool isStrictReference();
	bool isUnresolvableReference();
	bool HasPrimitiveBase();
	virtual ~Reference();
};

