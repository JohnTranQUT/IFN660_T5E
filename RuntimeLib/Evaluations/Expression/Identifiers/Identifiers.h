#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>

CompletionType *InitializeBoundName(StringType *, LanguageType * = new UndefinedType(), EnvironmentRecord * = nullptr);
