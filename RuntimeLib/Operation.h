#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "RuntimeLib/Type.h"
#define DEBUG



JSValue* addition(JSValue *lref, JSValue *rref);
JSValue* substraction(JSValue* lref, JSValue *rref);
JSValue* assignment(JSValue* lref, JSValue* rref);

//The folloing operations are used to operate on references
JSValue* GetValue(Type *v);
void PutValue(Type* v, JSValue* w);
std::string GetType(Type *type);
