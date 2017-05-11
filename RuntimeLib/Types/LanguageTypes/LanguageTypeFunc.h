#pragma once
#include <stdexcept>
#include <RuntimeLib/Types/LanguageTypes/LanguageType.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>
#include <RuntimeLib/Types/LanguageTypes/StringType/StringType.h>
#include <RuntimeLib/Types/LanguageTypes/NumberType/NumberType.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>

LanguageType *ToPrimitive(LanguageType *, LanguageType * = nullptr);
LanguageType *OrdinaryToPrimitive(ObjectType *, string hint);
BooleanType *ToBoolean(LanguageType *);
NumberType *ToNumber(LanguageType *);
NumberType *ToInteger(LanguageType *);
StringType *ToString(LanguageType *);
ObjectType *ToObject(LanguageType *);
LanguageType *_ToLanguageType(Type *, bool = true);
bool _CheckIfObject(LanguageType *);
string _TrimDecimal(string);
