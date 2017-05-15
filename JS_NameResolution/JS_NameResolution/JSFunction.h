#pragma once
#include <iostream>
#include "JSValue.h"
#include "JSReference.h"
#include <map>

JSValue* GetValue(JSValue* V)
{
	//If Type(V) is not Reference, return V.
	JSReference *ref = dynamic_cast<JSReference*>(V);
	if (ref == NULL)
		return V;
	//Return base.[[Get]](GetReferencedName(V), GetThisValue(V)).
	return	ref->base->get(ref->name);
}


JSValue* ToPrimitive(JSValue* input) {
	if (input->Type() == String || input->Type() == Number || input->Type() == Bool)
		return input;
	return NULL;
}


JSValue* Addition(JSValue* lref, JSValue* rref) {
	//Let lref be the result of evaluating AdditiveExpression.
	//Let lval be GetValue(lref).
	JSValue* lval = GetValue(lref);
	//ReturnIfAbrupt(lval).
	//Let rref be the result of evaluating MultiplicativeExpression.
	//Let rval be GetValue(rref).
	JSValue* rval = GetValue(rref);
	//ReturnIfAbrupt(rval).
	//Let lprim be ToPrimitive(lval).
	JSValue* lprim = ToPrimitive(lval);
	//ReturnIfAbrupt(lprim).
	//Let rprim be ToPrimitive(rval).
	JSValue* rprim = ToPrimitive(rval);
	//ReturnIfAbrupt(rprim).
	if (lprim->Type() == String || rprim->Type() == String) {
		/*If Type(lprim) is String or Type(rprim) is String, then
		Let lstr be ToString(lprim).
		ReturnIfAbrupt(lstr).
		Let rstr be ToString(rprim).
		ReturnIfAbrupt(rstr).
		Return the String that is the result of concatenating lstr and rstr.
		*/
		return new JSString(lprim->ToString()->value + rprim->ToString()->value);
	}
	else
		/*Let lnum be ToNumber(lprim).
		ReturnIfAbrupt(lnum).
		Let rnum be ToNumber(rprim).
		ReturnIfAbrupt(rnum).
		Return the result of applying the addition operation to lnum and rnum.See the Note below 12.7.5.
		*/
		return new JSNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
}

bool PutValue(JSValue* V, JSValue* W)
{
	//if Type(V) is not Reference, throw a ReferenceError exception.
	JSReference *ref = dynamic_cast<JSReference*>(V);
	if (ref == NULL)
		throw new std::exception("Reference error");
	//let succeeded be base.[[Set]](GetReferencedName(V), W, GetThisValue(V)).
	ref->base->set(ref->name, W);
	return true;
}

JSValue* Multiplication(JSValue* lref, JSValue* rref) {
	/*
	//Let left be the result of evaluating MultiplicativeExpression.
	//Let leftValue be GetValue(left).
	jsValue* lval = GetValue(lref);
	//ReturnIfAbrupt(leftValue).
	//Let right be the result of evaluating UnaryExpression.
	//Let rightValue be GetValue(right).
	jsValue* rval = GetValue(rref);
	//Let lnum be ToNumber(leftValue).

	//ReturnIfAbrupt(lnum).
	//Let rnum be ToNumber(rightValue).
	//ReturnIfAbrupt(rnum).
	//Return the result of applying the MultiplicativeOperator(*, / , or %) to lnum and rnum
	return new jsNumber(lval->ToNumber()->value * rval->ToNumber()->value);
	*/

	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	JSValue* lprim = ToPrimitive(lval);
	JSValue* rprim = ToPrimitive(rval);


	if (lprim->Type() == String || rprim->Type() == String) {
		JSValue* lprimValue = new JSBoolean(lprim->ToNumber()->value);
		JSValue* rprimValue = new JSBoolean(rprim->ToNumber()->value);

		if (lprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		else if (rprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		else
			return new JSNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);

	}

	else if (lprim->Type() == Number || rprim->Type() == String) {
		JSValue* rprimValue = new JSBoolean(rprim->ToNumber()->value);
		if (rprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		else
			return new JSNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);

	}


	else if (lprim->Type() == String || rprim->Type() == Number) {
		JSValue* lprimValue = new JSBoolean(lprim->ToNumber()->value);
		if (lprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		else
			return new JSNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);

	}
	else if (lprim->Type() == Number || rprim->Type() == Number) {
		return new JSNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);
	}

}

JSValue* Assign(JSValue* lref, JSValue* rref)
{
	//1.D Let rval be GetValue(rref)
	JSValue* rval = GetValue(rref);
	//1.F Let status be PutValue(lref, rval)
	bool status = PutValue(lref, rval);
	//1.G return rval
	return rval;
}

//Runtime Addition 
JSValue* Increment(JSValue* lref) { //12.4.4 on ECMA 6.0 ++
	JSValue* lval = GetValue(lref);
	JSValue* lprim = ToPrimitive(lval);
	//Let expr be the result of evaluating UnaryExpression.
	//Let oldValue be ToNumber(GetValue(expr)).
	JSValue* oldValue = GetValue(lprim)->ToNumber();
	//ReturnIfAbrupt(oldValue).
	//Let newValue be the result of adding the value 1 to oldValue, using the same rules as for the + operator (see 12.7.5).
	JSValue* newValue = Addition(oldValue, new JSNumber(1));
	//Let status be PutValue(expr, newValue).
	//ReturnIfAbrupt(status).
	//Return newValue.
	return newValue;
}

//Substraction 
JSValue* Substraction(JSValue* lref, JSValue* rref) {
	JSValue* lval = GetValue(lref);
	JSValue* rval = GetValue(rref);
	JSValue* lprim = ToPrimitive(lval);
	JSValue* rprim = ToPrimitive(rval);
	return new JSNumber(lprim->ToNumber()->value - rprim->ToNumber()->value);
}

//Decrement Operator Runtime Decrease 
JSValue* Decrement(JSValue* lref) { //12.5.8 on ECMA 6.0 --
	JSValue* lval = GetValue(lref);
	JSValue* lprim = ToPrimitive(lval);
	lprim = lprim->ToNumber();
	lprim = Substraction(lprim, new JSNumber(1));
	return lprim;
}

JSValue* AbstractEqual(JSValue* lprim, JSValue* rprim) { //7.2.12 


     if ((lprim->Type() == Number) && (rprim->Type() == String)) 

	{ return new JSBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value); }

	else if ((lprim->Type() == String) && (rprim->Type() == Number)) 

	{ return new JSBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value); }
	
	else if (lprim->Type() == Bool) 

	{ return new JSBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value); }

	else if (rprim->Type() == Bool) 

	{ return new JSBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value); }

	else if (lprim->Type() == String || lprim->Type() == Number) 

	{ return new JSBoolean(ToPrimitive(lprim) == ToPrimitive(rprim)); }

	else return new JSBoolean(false);
}

JSValue* Equal(JSValue* lref, JSValue* rref) { //12.10.03 Runtime EqualityExpression ==
	//Let lref be the result of evaluating EqualityExpression.
	//Let lval be GetValue(lref). -- Use lprim instead to work with the previously written codes.
	JSValue*  lval = GetValue(lref);
	//ReturnIfAbrupt(lval).
	//Let rref be the result of evaluating RelationalExpression.
	//Let rval be GetValue(rref). -- Use rprim instead to work with the previously written codes.
	JSValue* rval = GetValue(rref);
	//ReturnIfAbrupt(rval).
	//Return the result of performing Abstract Equality Comparison rval == lval.
	//	1.	ReturnIfAbrupt(x).
	//		2.	ReturnIfAbrupt(y).
	//		3.	If Type(x) is the same as Type(y), then
	//		a.Return the result of performing Strict Equality Comparison    x == = y.
	return AbstractEqual(rval, lval);
}

JSValue* NotEqual(JSValue* lref, JSValue* rref) { // 12.10.3 Runtime NotEqual !=

	JSValue* r = Equal(lref, rref);
	if (r->ToBool()->value) { return new JSBoolean(false); }
	else { return new JSBoolean(true); }
}
