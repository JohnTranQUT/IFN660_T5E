#pragma once
#include <RuntimeLib\Type\SpecificationType\CompletionRecordType\CompletionRecordType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>

CompletionRecordType* NormalCompletion(LanguageType* arguement);
CompletionRecordType* NormalCompletion(string infinity);
CompletionRecordType* ThrowAnException();
Type* ReturnIfAbrupt(Type* arguement);
CompletionRecordType* UpdateEmpty(CompletionRecordType* completionRecord, LanguageType* value);