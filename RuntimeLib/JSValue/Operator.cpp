#include "Operator.h"
#include <iostream>

JSValue* addition(JSValue *lref, JSValue *rref) {
	//AdditiveExpression: AdditiveExpression + MultiplicativeExpression
	//Let lref be the result of evaluating AdditiveExpression.
	//Let rref be the result of evaluating MultiplicativeExpression.

	//Let lval be ? GetValue(lref).
	JSValue* lval = GetValue(lref);
	//Let rval be ? GetValue(rref).
	JSValue* rval = GetValue(rref);
	
	//Let lprim be ? ToPrimitive(lval).
	auto lprim = lval->ToPrimitive();

	//Let rprim be ? ToPrimitive(rval).
	auto rprim = rval->ToPrimitive();
	if (GetType(lprim) == "string" || GetType( rprim) == "string") 
	{
		std::string str = lprim->ToString() + rprim->ToString();
		//Return the String that is the result of concatenating lstr and rstr.
		StringValue* result = new StringValue(str);
#ifdef DEBUG
		cout << "(" << GetType(lprim) << ")" << lprim->ToString() << " + (" << GetType(rprim) << ")" << rprim->ToString()<<" = ";
		cout << "(" << GetType(result) << ") \"" << result->ToString()<<"\"\n";
#endif 
		return result;
	} 	else 
	{
		//Return the result of applying the addition operation to lnum and rnum
		NumberValue *result = new NumberValue(lprim->ToNumber() + rprim->ToNumber());
		
#ifdef DEBUG
		cout << "(" << GetType(lprim) << ")" << lprim->ToString() << " + (" << GetType(rprim) << ")" << rprim->ToString() << " = ";
		cout << "(" << GetType(result) << ")" << result->ToString() <<"\n";
#endif 
		return result;
	}
}

JSValue* substraction(JSValue* lref, JSValue* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);

	double lnum = lval->ToNumber();
	double rnum = rval->ToNumber();

	NumberValue *result = new NumberValue(lnum - rnum);
	//substraction funtion always returns a NumberValue
	return result;
}
/*
JSValue* assignment(JSValue* lref, JSValue* rref)
{
	JSValue* rval = GetValue(rref);
	PutValue(lref, rval);
	return rval;

}
void PutValue(JSValue* v, JSValue* w)
{
	if (GetType(v)!="reference") {
		printf("ReferenceError");
	}else
	{
		auto base = GetBase(v);
		if (IsUnresolvableReference(v))
		{
			if (IsStrictReference(v))
			{
				printf("Throw error");
			}
		}
 	}
}

*/
std::string GetType(JSValue* type)
{
	if (dynamic_cast<BooleanValue*>(type))
	{
		return "boolean";
	} else if (dynamic_cast<StringValue*>(type))
	{
		return "string";
	} else if (dynamic_cast<NumberValue*>(type))
	{
		return "number";
	} else if (dynamic_cast<NullValue*>(type))
	{
		return "null";
	} else if (dynamic_cast<UndefinedValue*>(type))
	{
		return "undefined";
	} else if (dynamic_cast<ObjectValue*>(type))
	{
		return "object";
	} else if (dynamic_cast<Reference*>(type))
	{
		return "reference";
	} else
	{
		return "JSValue";
	}
}

JSValue* GetValue(JSValue *v) {
	if (GetType(v)!="reference")
	{
		return v;
	} 
	//More implementation here
}

