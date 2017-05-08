#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\CompletionRecord\CompletionRecord.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>

CompletionRecord* NormalCompletion(LanguageType* arguement);
CompletionRecord* NormalCompletion(string infinity);
CompletionRecord* ThrowAnException();
Type* ReturnIfAbrupt(Type* arguement);
CompletionRecord* UpdateEmpty(CompletionRecord* completionRecord, LanguageType* value);