#include "JSValue.h"


StringValue::StringValue(std::string value): value(value)
{
	
}

bool StringValue::ToBoolean()
{
	return (value.length()) ?  false : true;
}

std::string StringValue::ToString()
{
	return value;
}

double StringValue::ToNumber()
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
void StringValue::dump(int indent)
{
	label(indent, "StringValue\n");
}
*/

StringValue::~StringValue()
{
}


