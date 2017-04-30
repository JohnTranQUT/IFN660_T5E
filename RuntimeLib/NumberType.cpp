#include <sstream> // stringstream
#include "Type.h"

NumberType::NumberType(double _value)
{
	value = _value;
}

std::string NumberType::ToString()
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
