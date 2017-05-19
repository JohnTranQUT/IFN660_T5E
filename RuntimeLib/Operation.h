#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "RuntimeLib/Type.h"


class LexicalEnvironment;

JSValue* addition(Type *lref, Type *rref);
JSValue* substraction(Type* lref, Type *rref);

JSValue* multiplication(Type* lref, Type* rref);
JSValue* division(Type* lref, Type* rref);

JSValue* assignment(Type* lref, Type* rref);


JSValue* abstractComparision(JSValue* x, JSValue* y, bool leftFirst);
JSValue* lessthan(Type* lref, Type* rref);
JSValue* less_or_EQ(Type* lref, Type* rref);
//The folloing operations are used to operate on references
JSValue* GetValue(Type *v);
void PutValue(Type* v, JSValue* w);
std::string GetType(Type *type);

