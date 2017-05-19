#include "Operation.h"
#include <iostream>
#include "SpecificationType/Reference.h"
#include "SpecificationType/Record/EnvironmentRecord.h"


JSValue* addition(Type *lref, Type *rref) {
	//AdditiveExpression: AdditiveExpression + MultiplicativeExpression
	//Let lval be  GetValue(lref).
	JSValue* lval = GetValue(lref);
	//Let rval be  GetValue(rref).
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
		return result;
	} 	else 
	{
		//Return the result of applying the addition operation to lnum and rnum
		NumberValue *result = new NumberValue(lprim->ToNumber() + rprim->ToNumber());	
		return result;
	}
}

JSValue* substraction(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);

	double lnum = lval->ToNumber();
	double rnum = rval->ToNumber();

	NumberValue *result = new NumberValue(lnum - rnum);
	//substraction funtion always returns a NumberValue
	return result;
}

JSValue* multiplication(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);

	double lnum = lval->ToNumber();
	double rnum = rval->ToNumber();

	NumberValue *result = new NumberValue(lnum * rnum);
	return result;
}

JSValue* division(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);

	double lnum = lval->ToNumber();
	double rnum = rval->ToNumber();

	NumberValue *result = new NumberValue(lnum / rnum);
	return result;
}

std::string GetType(Type* type)
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
		return "Type";
	}
}


JSValue* GetValue(Type *v) {
	if (GetType(v)!="reference")
	{
		return dynamic_cast<JSValue*>(v);
	} else
	{	//Type(V) is Reference
		Reference* reference = dynamic_cast<Reference*>(v);
		//let base be GetBase(v)
		//base must be an Environment Record
		EnvironmentRecord *base = dynamic_cast<EnvironmentRecord*>(reference->GetBase());
		std::string refName = reference->GetReferenceName();
		JSValue* value = base->GetBindingValue(refName);
		return value;
	}
	
}

void PutValue(Type* v, JSValue* w)
{
	//if Type(v) is not Reference, throw a ReferenceError exception
	if (GetType(v) != "reference") {
		fprintf(stderr, "ReferenceError\n");
	} else
	{
		Reference* reference = dynamic_cast<Reference*>(v);
		Type* base = reference->GetBase();
		if (reference->isUnresolvableReference())
		{
			if (reference->isStrictReference())
			{
				printf("ReferenceError");
				exit(0);
			}
		}
		//base must be an Environment Record
		EnvironmentRecord *envr = dynamic_cast<EnvironmentRecord*>(base);
		std::string name = reference->GetReferenceName();
		envr->SetMutableBinding(name, w);
	}
}

JSValue* assignment(Type* lref, Type* rref)
{
	//Assignment Expression: LeftHandSideExpression = AssignmentExpression
	JSValue *rval = GetValue(rref);
	PutValue(lref, rval);
	return rval;

}
