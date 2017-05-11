#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>

CompletionRecord *InitializeBoundName(StringType *, LanguageType * = new UndefinedType(), EnvironmentRecord * = nullptr);
