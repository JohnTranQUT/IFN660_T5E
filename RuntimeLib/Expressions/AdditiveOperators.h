#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageTypeFunc.h>

LanguageType* additiveOperator(LanguageType* lref, LanguageType* rref);
LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref);

//==================================ReferenceType functions==========================
LanguageType* GetValue(LanguageType* V);
void ReturnIfAbrupt(LanguageType* V);