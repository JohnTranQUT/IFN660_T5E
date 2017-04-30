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
	double result = 0;
	try {
		//convert a string to double
		result = std::stod(value);
	}
	catch (const std::invalid_argument& ia) {
		//If the value cannot be interpreted as a string
		//then the result of ToNumber is NaN.
		result = NAN;
	}
	
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


