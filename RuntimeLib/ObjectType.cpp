#include "Type.h"

JSObject::JSObject(map<std::string, std::string> _value): map_value(_value)
{

}

Type* JSObject::ToPrimitive() {
	
	string result = "{";
	for (map<string, string>::iterator iter = map_value.begin(); iter != map_value.end(); iter++)
	{
		result += "'" + iter->first + "': ";
		result += "'" + iter->second + "',";
	}
	result.pop_back();//Remove the last character
	result += "}";
	JSString* jsStr = new JSString(result);
	return jsStr;
}

bool JSObject::ToBoolean()
{
	return true;
}

double JSObject::ToNumber()
{
	return NAN;
}

std::string JSObject::ToString()
{
	Type* primValue = this->ToPrimitive();
	return primValue->ToString();
}


JSObject::~JSObject()
{
}
