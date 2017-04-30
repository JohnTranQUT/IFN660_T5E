#pragma once
#include <Types/LanguageTypes/ObjectType/ObjectType.h>
#include <Types/LanguageTypes/LanguageTypesFunc.h>

ObjectType *Object(LanguageType * = nullptr);
ObjectType *Boolean(LanguageType * = new BooleanType(false));
ObjectType *Number(LanguageType * = new NumberType(0));
ObjectType *String(LanguageType * = new StringType(""));