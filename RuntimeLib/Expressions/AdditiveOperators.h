#pragma once
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>

LanguageType* additiveOperator(LanguageType* lref, LanguageType* rref);
LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref);

LanguageType* GetValue(LanguageType* V);
LanguageType* ToPrimative(LanguageType* input, LanguageType* preferredType = nullptr);

StringType* ToString(LanguageType* V);
NumberType* ToNumber(LanguageType* V);
BooleanType* ToBoolean(LanguageType* V);

void ReturnIfAbrupt(LanguageType* V);