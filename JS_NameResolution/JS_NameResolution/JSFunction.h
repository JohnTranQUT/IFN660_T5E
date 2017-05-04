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

