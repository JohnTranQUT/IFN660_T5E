#include "JSValue.h"

ObjectValue::ObjectValue(map<std::string, std::string> _value): map_value(_value)
{

}

JSValue* ObjectValue::ToPrimitive() {
	
	string result = "{";
	for (map<string, string>::iterator iter = map_value.begin(); iter != map_value.end(); iter++)
	{
		result += "'" + iter->first + "': ";
		result += "'" + iter->second + "',";
	}
	result.pop_back();//Remove the last character
	result += "}";
	StringValue* jsStr = new StringValue(result);
	return jsStr;
}

bool ObjectValue::ToBoolean()
{
	return true;
}

double ObjectValue::ToNumber()
{
	return NAN;
}

std::string ObjectValue::ToString()
{
	JSValue* primValue = this->ToPrimitive();
	return primValue->ToString();
}
/*
void ObjectValue::dump(int indent)
{
	label(indent, "ObjectValue\n");
}
*/

ObjectValue::~ObjectValue()
{
}
