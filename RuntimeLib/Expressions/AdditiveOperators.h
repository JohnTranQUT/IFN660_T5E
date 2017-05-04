#pragma once
#include <RuntimeLib\Type\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\NullType\NullType.h>
#include <RuntimeLib\Type\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\NumberType\NumberType.h>
#include <RuntimeLib\Type\StringType\StringType.h>
#include <RuntimeLib\Type\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\ObjectType\ObjectType.h>

Type* additiveOperator(Type* lref, Type* rref);
Type* subtractiveOperator(Type* lref, Type* rref);

Type* GetValue(Type* V);
Type* ToPrimative(Type* input, Type* preferredType = nullptr);

StringType* ToString(Type* V);
NumberType* ToNumber(Type* V);

void ReturnIfAbrupt(Type* V);