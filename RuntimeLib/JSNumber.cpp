#include "JSValue.h"

JSNumber::JSNumber(double _value)
{
	value = _value;
}

std::string JSNumber::ToString()
{
	return std::to_string(value);
}

double JSNumber::ToNumber()
{
	return value;
}

JSNumber::~JSNumber()
{
}
