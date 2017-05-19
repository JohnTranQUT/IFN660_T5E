#include "Operation.h"
#include <iostream>
#include "SpecificationType/Reference.h"
#include "SpecificationType/Record/EnvironmentRecord.h"
#include <algorithm>


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
//7.2.12 Implementaion
JSValue* abstractComparision(JSValue* x, JSValue* y,bool leftFirst)
{
	JSValue* px;
	JSValue* py;
	if (leftFirst)
	{
		px = x->ToPrimitive();
		py = y->ToPrimitive();
	}else
	{
		px = y->ToPrimitive();
		py = x->ToPrimitive();
	}
	
	if (GetType(px)=="string" && GetType(py)=="string" )
	{
		string sx = px->ToString();
		string sy = py->ToString();
		auto res = std::mismatch(sx.begin(), sx.end(), sy.begin());
		if (res.first == sx.end())
		{
			//px is prefix of py
			return new BooleanValue(true);
		}
		else return new BooleanValue(false);
	} else
	{
		double nx = px->ToNumber();
		double ny = py->ToNumber();
		if (isnan(nx) || isnan(ny))
		{
			//return Undefined if x or y is NaN
			return new UndefinedValue();
		} else
		{
			return new BooleanValue(nx < ny);
		}
	}
}
//12.10.3 Implementation
JSValue* lessThan(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	//Let r be the result of performing Abstract Relational Comparison lval < rval.
	JSValue* r = abstractComparision(lval, rval,true);
	//If r is undefined, return false
	if (dynamic_cast<UndefinedValue*>(r))
	{
		return new BooleanValue(false);
	}
	//Otherwise, return r.
	else return r;
}
//12.10.3 Implementation
JSValue* lessOrEQual(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	JSValue* r = abstractComparision(lval, rval, true);
	//If r is true or undefined, return false. 
	//Otherwise, return true.
	if (dynamic_cast<UndefinedValue*>(r))
	{
		return new BooleanValue(false);
	} else
	{
		BooleanValue *result = dynamic_cast<BooleanValue*>(r);
		if (result->ToBoolean()) return new BooleanValue(false);
		else return new BooleanValue(true);
	}
}
JSValue* greaterThan(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	JSValue* r = abstractComparision(lval,rval, false);
	//If r is undefined, return false
	if (dynamic_cast<UndefinedValue*>(r))
	{
		return new BooleanValue(false);
	}
	//Otherwise, return r.
	else return r;
}

JSValue* greaterOrEQual(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	JSValue* r = abstractComparision(lval,rval, true);
	//If r is true or undefined, return false. 
	//Otherwise, return true.
	if (dynamic_cast<UndefinedValue*>(r))
	{
		return new BooleanValue(false);
	}
	else
	{
		BooleanValue *result = dynamic_cast<BooleanValue*>(r);
		if (result->ToBoolean()) return new BooleanValue(false);
		else return new BooleanValue(true);
	}
}

//7.2.13 Implementation
//Fix me
JSValue* abstractEqualityComparision(JSValue* x, JSValue* y)
{
	if (GetType(x)=="number"&& GetType(y)=="number")
	{
		if (x->ToNumber()==y->ToNumber())
		{
			return new BooleanValue(true);
		}
		else return new BooleanValue(false);
	} else return new BooleanValue(false);
}

//12.11.3 implementation
JSValue* isEqual(Type* lref, Type* rref)
{
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	return abstractEqualityComparision(lval, rval);
}

JSValue* increment(Type* expr)
{
	//Let oldValue be ? ToNumber(? GetValue(lhs)).
	JSValue *val = GetValue(expr);
	double oldValue = val->ToNumber();
	//Let newValue be the result of adding the value 1 to oldValue, 
	NumberValue *new_value = new NumberValue(oldValue + 1);
	PutValue(expr, new_value);
	return new NumberValue(oldValue);

}
