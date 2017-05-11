#pragma once
#include <stdexcept>
#include <RuntimeLib/Types/LanguageTypes/LanguageType.h>
#include <RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <RuntimeLib/Types/LanguageTypes/NullType/NullType.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>
#include <RuntimeLib/Types/LanguageTypes/StringType/StringType.h>
#include <RuntimeLib/Types/LanguageTypes/SymbolType/SymbolType.h>
#include <RuntimeLib/Types/LanguageTypes/NumberType/NumberType.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/ObjectObject/ObjectObject.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/BooleanObject/BooleanObject.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/NumberObject/NumberObject.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/StringObject/StringObject.h>

LanguageType *ToPrimitive(LanguageType *, LanguageType * = nullptr);
LanguageType *OrdinaryToPrimitive(ObjectType *, string hint);
BooleanType *ToBoolean(LanguageType *);
NumberType *ToNumber(LanguageType *);
NumberType *ToInteger(LanguageType *);
StringType *ToString(LanguageType *);
ObjectType *ToObject(LanguageType *);
string _GetType(LanguageType *);
LanguageType *_ToLanguageType(Type *, bool = true);
bool _CheckIfObject(LanguageType *);
string _TrimDecimal(string);
