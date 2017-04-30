#include "Operator.h"

Type* addition(Type *lref, Type *rref) {
	Type* lval = GetValue(lref);
	Type* rval = GetValue(rref);
	
	auto lprim = lval->ToPrimitive();
	auto rprim = rval->ToPrimitive();
	if (GetType(lprim) == "string" || GetType(rprim) == "string") 
	{
		std::string str = lprim->ToString() + rprim->ToString();
		StringType* result = new StringType(str);
		return result;
	} 	else 
	{
		return new NumberType(lprim->ToNumber() + rprim->ToNumber());
	}
}

Type* substraction(Type* lref, Type* rref)
{
	Type* lval = GetValue(lref);
	Type* rval = GetValue(rref);

	double lnum = lval->ToNumber();
	double rnum = rval->ToNumber();

	NumberType *result = new NumberType(lnum - rnum);
	//substraction funtion always returns a NumberType
	return result;
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

