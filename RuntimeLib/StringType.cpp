#include "Type.h"


StringType::StringType(std::string value): value(value)
{
	
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
/*
void StringType::dump(int indent)
{
	label(indent, "StringType\n");
}
*/

StringType::~StringType()
{
}


