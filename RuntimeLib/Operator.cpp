#include "Operator.h"

Type* addition(Type *lref, Type *rref) {
	Type* lval = GetValue(lref);
	Type* rval = GetValue(rref);
	
	auto lprim = lval->ToPrimitive();
	auto rprim = rval->ToPrimitive();
	if (GetType(lprim) == "string" || GetType(rprim) == "string") {
		std::string result = lprim->ToString() + rprim->ToString();
		StringType* str = new StringType(result);
		return str;
	} 
	else {
		return new NumberType(lprim->ToNumber() + rprim->ToNumber());
	}
}
std::string GetType(Type* type)
{
	if (dynamic_cast<BooleanType*>(type))
	{
		return "string";
	} else if (dynamic_cast<StringType*>(type))
	{
		return "string";
	} else if (dynamic_cast<NumberType*>(type))
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

