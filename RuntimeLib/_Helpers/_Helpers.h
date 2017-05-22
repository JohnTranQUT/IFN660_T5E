#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Record/Record.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"

void _calculate(LanguageType *, string, LanguageType *);
void _listItemsInRecord(Record *);
BooleanType *_sameType(LanguageType *, LanguageType *);
CompletionRecord *_log(Type *);
