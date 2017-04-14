#include "JSValue.h"

JSValue::~JSValue()
{
	std::cout << "JSValue destructor\n";
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
