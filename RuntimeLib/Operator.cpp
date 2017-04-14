#include "Operator.h"

JSValue* addition(JSValue *lref, JSValue *rref) {
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	
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
string Type(JSValue* js_value)
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
		return "JSValue";
	}
}

JSValue* GetValue(JSValue *object) {
	return object;
}

