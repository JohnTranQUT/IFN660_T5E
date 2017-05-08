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


