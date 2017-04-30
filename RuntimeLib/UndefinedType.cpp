#include "Type.h"
#include <iostream>

Type::~Type()
{
	std::cout << "Type destructor\n";
}

bool JSUndefined::ToBoolean()
{
	return false;
}

std::string JSUndefined::ToString()
{
	return "undefined";
}

double JSUndefined::ToNumber()
{
	return NAN;
}

JSUndefined::JSUndefined()
{
	
}

JSUndefined::~JSUndefined()
{
	
}
