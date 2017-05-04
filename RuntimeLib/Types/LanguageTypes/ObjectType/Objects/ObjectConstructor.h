#pragma once
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypesFunc.h>

ObjectType *Object(LanguageType * = nullptr);
ObjectType *Boolean(LanguageType * = new BooleanType(false));
ObjectType *Number(LanguageType * = new NumberType(0));
ObjectType *String(LanguageType * = new StringType(""));
