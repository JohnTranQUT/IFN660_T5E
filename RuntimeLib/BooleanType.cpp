#include "Type.h"



JSBoolean::JSBoolean(bool _value)
{
	value = _value;
}
bool JSBoolean::ToBoolean()
{
	return value;
}

std::string JSBoolean::ToString()
{
	return value ? "true" : false;
}

double JSBoolean::ToNumber()
{
	return (value) ? 1 : 0;
}

JSBoolean::~JSBoolean()
{
}
