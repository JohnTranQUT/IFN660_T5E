#include "Reference.h"


Reference::Reference(JSValue* base, std::string name): base(base),name(name)
{
	strictReference = false;
}

JSValue* Reference::GetBase()
{
	return base;
}

std::string Reference::GetReferenceName()
{
	return name;
}

bool Reference::isStrictReference()
{
	return strictReference;
}

bool Reference::isUnresolvableReference()
{
	return (GetType(base) == "undefined") ? true : false;
}

Reference::~Reference()
{
}
