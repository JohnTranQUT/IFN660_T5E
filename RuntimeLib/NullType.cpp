#include "Type.h"



NullType::NullType()
{
}

std::string NullType::ToString()
{
	return "null";
}


double NullType::ToNumber()
{
	return +0;
}
/*
void NullType::dump(int indent)
{
	label(indent, "NullType\n");
}
*/

NullType::~NullType()
{
}
