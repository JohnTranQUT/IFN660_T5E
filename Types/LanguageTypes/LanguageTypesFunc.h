#pragma once
#include <stdexcept>
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <Types/LanguageTypes/NullType/NullType.h>
#include <Types/LanguageTypes/BooleanType/BooleanType.h>
#include <Types/LanguageTypes/StringType/StringType.h>
#include <Types/LanguageTypes/SymbolType/SymbolType.h>
#include <Types/LanguageTypes/NumberType/NumberType.h>
#include <Types/LanguageTypes/ObjectType/ObjectType.h>
#include <Objects/ObjectObject/ObjectObject.h>
#include <Objects/BooleanObject/BooleanObject.h>
#include <Objects/NumberObject/NumberObject.h>
#include <Objects/StringObject/StringObject.h>

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