#include "JSValue.h"



JSNull::JSNull()
{
}

std::string JSNull::ToString()
{
	return "null";
}


double JSNull::ToNumber()
{
	return +0;
}


JSNull::~JSNull()
{
}
