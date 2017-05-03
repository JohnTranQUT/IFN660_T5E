#include "Reference.h"
#include "RuntimeLib/Operation.h"


Reference::Reference(Type* base, std::string name): base(base),name(name)
{
	strictReference = false;
}

Type* Reference::GetBase()
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
