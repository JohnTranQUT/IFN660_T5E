#include "Operation.h"
#include <iostream>
#include "SpecificationType/Reference.h"
#include "SpecificationType/Record/EnvironmentRecord.h"

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


*/
std::string GetType(Type* type)
{
	if (static_cast<BooleanValue*>(type))
	{
		return "boolean";
	} else if (static_cast<StringValue*>(type))
	{
		return "string";
	} else if (static_cast<NumberValue*>(type))
	{
		return "number";
	} else if (static_cast<NullValue*>(type))
	{
		return "null";
	} else if (static_cast<UndefinedValue*>(type))
	{
		return "undefined";
	} else if (static_cast<ObjectValue*>(type))
	{
		return "object";
	} else if (static_cast<Reference*>(type))
	{
		return "reference";
	} else
	{
		return "Type";
	}
}

JSValue* GetValue(Type *v) {
	if (GetType(v)!="reference")
	{
		return static_cast<JSValue*>(v);
	} else
	{	//Type(V) is Reference
		Reference* reference = static_cast<Reference*>(v);
		//let base be GetBase(v)
		//base must be an Environment Record
		EnvironmentRecord *base = static_cast<EnvironmentRecord*>(reference->GetBase());
		std::string refName = reference->GetReferenceName();
		JSValue* value = base->GetBindingValue(refName);
		return value;
	}
	
}

void PutValue(Type* v, JSValue* w)
{
	//if Type(v) is not Reference, throw a ReferenceError exception
	if (GetType(v) != "reference") {
		throw new std::exception("ReferenceError");
	} else
	{
		Reference* reference = static_cast<Reference*>(v);
		Type* base = reference->GetBase();
		//base must be an Environment Record
		EnvironmentRecord *envr = static_cast<EnvironmentRecord*>(base);

		std::string name = reference->GetReferenceName();
		envr->SetMutableBinding(name, w);
	}
}