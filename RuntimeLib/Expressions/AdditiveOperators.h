#pragma once
#include <RuntimeLib\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\LanguageType\NullType\NullType.h>
#include <RuntimeLib\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\LanguageType\StringType\StringType.h>
#include <RuntimeLib\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\LanguageType\ObjectType\ObjectType.h>

LanguageType* additiveOperator(LanguageType* lref, LanguageType* rref);
LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref);

LanguageType* GetValue(LanguageType* V);
LanguageType* ToPrimative(LanguageType* input, LanguageType* preferredType = nullptr);

StringType* ToString(LanguageType* V);
NumberType* ToNumber(LanguageType* V);

void ReturnIfAbrupt(LanguageType* V);
