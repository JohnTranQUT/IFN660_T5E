#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h>

CompletionRecord *InitializeBoundName(StringType *, LanguageType * = new UndefinedType(), EnvironmentRecord * = nullptr);
