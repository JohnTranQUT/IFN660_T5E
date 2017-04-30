#include "Type.h"
#include <iostream>

Type::~Type()
{
	std::cout << "Type destructor\n";
}

bool UndefinedType::ToBoolean()
{
	return false;
}

std::string UndefinedType::ToString()
{
	return "undefined";
}

double UndefinedType::ToNumber()
{
	return NAN;
}
/*
void UndefinedType::dump(int indent)
{
	label(indent, "UndefinedType\n");
}
*/

UndefinedType::UndefinedType()
{
	
}

UndefinedType::~UndefinedType()
{
	
}
