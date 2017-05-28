#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageTypeFunc.h>
#include <RuntimeLib\Type\SpecificationType\Reference\ReferenceFunc.h>
#include <string>

BooleanType* Equality(Type* lref, Type* rref);
BooleanType* AbstractEqualityComparison(LanguageType* x, LanguageType* y);
BooleanType* StrictEqualityComparsion(LanguageType* x, LanguageType* y);
BooleanType* SameValueNonNumber(LanguageType* x, LanguageType* y);
string TypeOf(LanguageType * x);
