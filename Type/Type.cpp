#pragma once
#include "Type.h"
#include "SpecificationType.h"
using namespace std;

string ToString(Type _type) { return _type.to_string(); };

Type* ToPrimitive(Type* _type, string PreferredType)
{
	//if (typeid(_type) == typeid(Object))
	//{
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
	//}
	return _type;
}

Type* GetValue(Type* V)
{
	//  1. ReturnIfAbrupt(V). NOT IMPLEMENTED

	//	2. If Type(V) is not Reference, return V. -Return V at ELSE section
	if (Reference* V_ref = dynamic_cast<Reference*>(V))
	{
		//	3. Let base be GetBase(V).
		auto base = GetBase(V_ref);
		//	4. If IsUnresolvableReference(V) is true, throw a ReferenceError exception.

		//	5. If IsPropertyReference(V) is true, then
		//	    a. If HasPrimitiveBase(V) is true, then
		//	        i. Assert : In this case, base will never be null or undefined.
		//	       ii. Let base be ToObject(base).
		//	    b. Return ? base.[[Get]](GetReferencedName(V), GetThisValue(V)).
		//	6. Else base must be an Environment Record,
		//	    a.Return ? base.GetBindingValue(GetReferencedName(V), IsStrictReference(V)) (see 8.1.1).

	}
	return V;
}