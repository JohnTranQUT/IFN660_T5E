#pragma once
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Type\SpecificationType\CompletionRecordType\CompletionRecordTypeFunc.h>

LanguageType* GetValue(LanguageType* V);
LanguageType* PutValue(Type* V, Type* W);

//Specification Functions?
Type* GetGlobalObject();