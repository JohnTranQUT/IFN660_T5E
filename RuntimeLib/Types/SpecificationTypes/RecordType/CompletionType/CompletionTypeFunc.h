#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionType.h>

Type *ReturnIfAbrupt(CompletionType *);
CompletionType *NormalCompletion(LanguageType *);
