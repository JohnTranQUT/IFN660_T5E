#pragma once
#include "Type.h"

class Type;

Type* addition(Type *lref, Type *rref);
Type* GetValue(Type *object);
std::string GetType(Type *type);
