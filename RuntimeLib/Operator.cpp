#include "Operator.h"

Type* addition(Type *lref, Type *rref) {
	Type* lval = GetValue(lref);
	Type* rval = GetValue(rref);
	
	auto lprim = lval->ToPrimitive();
	auto rprim = rval->ToPrimitive();
	if (Type(lprim) == "string" || Type(rprim) == "string") {
		JSString* str = new JSString(lprim->ToString() + rprim->ToString());
		return str;
	} 
	else {
		return new JSNumber(lprim->ToNumber() + rprim->ToNumber());
	}
}
string Type(Type* js_value)
{
	if (dynamic_cast<JSBoolean*>(js_value))
	{
		return "string";
	} else if (dynamic_cast<JSString*>(js_value))
	{
		return "string";
	} else if (dynamic_cast<JSNumber*>(js_value))
	{
		return "number";
	} else
	{
		return "Type";
	}
}

Type* GetValue(Type *object) {
	return object;
}

