#include "JSValue.h"


JSString::JSString(std::string _value)
{
	value = _value;
}

bool JSString::ToBoolean()
{
	return (value.length()) ?  false : true;
}

std::string JSString::ToString()
{
	return value;
}

double JSString::ToNumber()
{
	double result = std::stoi(value);
	return result;
}

JSString::~JSString()
{
}


