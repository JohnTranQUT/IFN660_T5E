#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"

CompletionRecord::CompletionRecord(StringType *_Type, LanguageType *_Value, StringType *_Target) {
	_insertValue(new StringType("Type"), _Type);
	_insertValue(new StringType("Value"), _Value);
	_insertValue(new StringType("Target"), _Target);
}
