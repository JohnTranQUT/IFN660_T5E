#include "Type.h"

NumberType::NumberType(double _value)
{
	value = _value;
}

std::string NumberType::ToString()
{
	return std::to_string(value);
}

double NumberType::ToNumber()
{
	return value;
}
/*
void NumberType::dump(int indent)
{
	label(indent, "NumberType\n");
}
*/

NumberType::~NumberType()
{
}
