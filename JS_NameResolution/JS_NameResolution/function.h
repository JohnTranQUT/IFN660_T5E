#pragma once
#include <iostream>
#include "JSValue.h"
#include "JSReference.h"



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

}

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
