#include "JSValue.h"



NullValue::NullValue()
{
}

std::string NullValue::ToString()
{
	return "null";
}


double NullValue::ToNumber()
{
	return +0;
}
/*
void NullValue::dump(int indent)
{
	label(indent, "NullValue\n");
}
*/

NullValue::~NullValue()
{
}
