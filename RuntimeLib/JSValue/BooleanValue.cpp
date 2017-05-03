#include "JSValue.h"



BooleanValue::BooleanValue(bool _value)
{
	value = _value;
}
bool BooleanValue::ToBoolean()
{
	return value;
}

std::string BooleanValue::ToString()
{
	return value ? "true" : "false";
}

double BooleanValue::ToNumber()
{
	return (value) ? 1 : 0;
}
/*
void BooleanValue::dump(int indent)
{
	label(indent, "BooleanValue\n");
}
*/

BooleanValue::~BooleanValue()
{
}
