#include "Type.h"



BooleanType::BooleanType(bool _value)
{
	value = _value;
}
bool BooleanType::ToBoolean()
{
	return value;
}

std::string BooleanType::ToString()
{
	return value ? "true" : "false";
}

double BooleanType::ToNumber()
{
	return (value) ? 1 : 0;
}
/*
void BooleanType::dump(int indent)
{
	label(indent, "BooleanType\n");
}
*/

BooleanType::~BooleanType()
{
}
