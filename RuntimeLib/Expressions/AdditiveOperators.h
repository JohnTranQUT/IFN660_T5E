#pragma once
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>

LanguageType* AdditiveOperator(Type* lref, Type* rref);
LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref);


LanguageType* ToPrimative(LanguageType* input, LanguageType* preferredType = nullptr);

string ToString(LanguageType* V);
double ToNumber(LanguageType* V);
ObjectType* ToObject(Type* V);
