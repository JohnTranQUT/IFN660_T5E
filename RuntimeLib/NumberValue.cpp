#include <sstream> // stringstream
#include "JSValue.h"

NumberValue::NumberValue(double _value)
{
	value = _value;
}

std::string NumberValue::ToString()
{
	if (isnan(value))
	{
		return "NaN";
	} else
	{
		//Remove trailing zeros by using stringstream
		stringstream stream;
		stream << value;
		return  stream.str();
	}
	
}

double NumberValue::ToNumber()
{
	return value;
}
/*
void NumberValue::dump(int indent)
{
	label(indent, "NumberValue\n");
}
*/

NumberValue::~NumberValue()
{
}
