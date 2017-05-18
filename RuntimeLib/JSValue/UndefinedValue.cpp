#include "JSValue.h"
#include <iostream>

JSValue::~JSValue()
{
	std::cout << "JSValue destructor\n";
}

bool UndefinedValue::ToBoolean()
{
	return false;
}

std::string UndefinedValue::ToString()
{
	return "undefined";
}

double UndefinedValue::ToNumber()
{
	return NAN;
}
/*
void UndefinedValue::dump(int indent)
{
	label(indent, "UndefinedValue\n");
}
*/

UndefinedValue::UndefinedValue()
{
	
}

UndefinedValue::~UndefinedValue()
{
	
}
