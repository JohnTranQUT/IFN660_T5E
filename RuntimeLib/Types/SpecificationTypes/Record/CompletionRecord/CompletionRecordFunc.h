#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"

Type *ReturnIfAbrupt(CompletionRecord *);
CompletionRecord *NormalCompletion(LanguageType *);
