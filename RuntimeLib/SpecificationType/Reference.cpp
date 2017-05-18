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

bool Reference::HasPrimitiveBase()
{
	std::string type = GetType(base);
	if ((type=="BooleanValue") ||(type=="StringValue")||(type=="NumberValue"))
	{
		return true;
	}
	else return false;
}

Reference::~Reference()
{
}
