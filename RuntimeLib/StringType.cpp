#include "Type.h"


StringType::StringType(std::string _value)
{
	value = _value;
}

bool StringType::ToBoolean()
{
	return (value.length()) ?  false : true;
}

std::string StringType::ToString()
{
	return value;
}

double StringType::ToNumber()
{
	double result = std::stoi(value);
	return result;
}

StringType::~StringType()
{
}


