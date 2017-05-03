#include <Type.h>

std::string ToString(Type _type) { return _type.to_string(); };

Type ToPrimitive(Type _type, string PreferredType) 
{
	if (typeid(_type)==typeid(Object))
	{ 
		//1. If PreferredType was not passed, let hint be "default".
		//2. Else if PreferredType is hint String, let hint be "string".
		//3. Else PreferredType is hint Number, let hint be "number".
		//4. Let exoticToPrim be ? GetMethod(input, toPrimitive).
		//5. If exoticToPrim is not undefined, then
		//			a. Let result be ? Call(exoticToPrim, input, « hint »).
		//			b. If Type(result) is not Object, return result.
		//			c. Throw a TypeError exception.
		//6. If hint is "default", let hint be "number".
		//7. Return ? OrdinaryToPrimitive(input, hint).
	}
	return _type;
};