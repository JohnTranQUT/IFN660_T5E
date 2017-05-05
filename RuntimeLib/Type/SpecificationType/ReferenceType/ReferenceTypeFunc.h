#pragma once
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>

LanguageType* GetValue(LanguageType* V);
LanguageType* PutValue(Type* V, Type* W);

//Specification Functions?
void ReturnIfAbrupt(Type* V);
Type* GetGlobalObject();