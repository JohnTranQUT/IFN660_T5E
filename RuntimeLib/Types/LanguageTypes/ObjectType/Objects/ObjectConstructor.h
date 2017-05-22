#pragma once
#include "RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"
#include "RuntimeLib/Types/LanguageTypes/NumberType/NumberType.h"
#include "RuntimeLib/Types/LanguageTypes/StringType/StringType.h"

ObjectType *Object(LanguageType * = nullptr);
ObjectType *Boolean(LanguageType * = new BooleanType(false));
ObjectType *Number(LanguageType * = new NumberType(0));
ObjectType *String(LanguageType * = new StringType(""));
