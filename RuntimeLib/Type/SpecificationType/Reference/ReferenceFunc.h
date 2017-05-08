#pragma once
#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>

LanguageType* GetValue(LanguageType* V);
LanguageType* PutValue(Type* V, Type* W);

//Specification Functions?
Type* GetGlobalObject();