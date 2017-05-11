#pragma once
#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecordFunc.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecord.h>

LanguageType* GetValue(Type* V);
CompletionRecord* PutValue(Type* V, Type* W);
CompletionRecord* InitializedReferencedBinding(Type* V,Type* W);

//Specification Functions?
Type* GetGlobalObject();

CompletionRecord*  Set(Type* O, LanguageType* P, Type* V, BooleanType* Throw);