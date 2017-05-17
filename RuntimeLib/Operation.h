#pragma once
#include "RuntimeLib/JSValue/JSValue.h"
#include "RuntimeLib/Type.h"
#include "SpecificationType/Reference.h"
#define DEBUG

JSValue* addition(Type *lref, Type *rref);
JSValue* substraction(JSValue* lref, JSValue *rref);


//The folloing operations are used to operate on references
JSValue* GetValue(Type *v);
void PutValue(Type* v, JSValue* w);
std::string GetType(Type *type);
