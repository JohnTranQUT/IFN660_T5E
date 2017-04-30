#include "Type.h"

ObjectType::ObjectType(map<std::string, std::string> _value): map_value(_value)
{

}

Type* ObjectType::ToPrimitive() {
	
	string result = "{";
	for (map<string, string>::iterator iter = map_value.begin(); iter != map_value.end(); iter++)
	{
		result += "'" + iter->first + "': ";
		result += "'" + iter->second + "',";
	}
	result.pop_back();//Remove the last character
	result += "}";
	StringType* jsStr = new StringType(result);
	return jsStr;
}

bool ObjectType::ToBoolean()
{
	return true;
}

double ObjectType::ToNumber()
{
	return NAN;
}

std::string ObjectType::ToString()
{
	Type* primValue = this->ToPrimitive();
	return primValue->ToString();
}
/*
void ObjectType::dump(int indent)
{
	label(indent, "ObjectType\n");
}
*/

ObjectType::~ObjectType()
{
}
