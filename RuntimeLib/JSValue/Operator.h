#pragma once
#include "JSValue.h"
#include "AST/AstExpression.h"
#define DEBUG

class JSValue;

JSValue* addition(JSValue *lref, JSValue *rref);
JSValue* substraction(JSValue* lref, JSValue *rref);
JSValue* assignment(JSValue* lref, JSValue* rref);
JSValue* GetValue(JSValue *object);
std::string GetType(JSValue *type);
