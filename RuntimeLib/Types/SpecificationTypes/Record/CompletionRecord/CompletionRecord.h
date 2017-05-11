#pragma once
#include <RuntimeLib/Types/SpecificationTypes/SpecificationTypes.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/Record.h>

using namespace std;

class CompletionRecord : public Record {
public:
	explicit CompletionRecord(
		StringType *_Type,
		LanguageType *_Value,
		StringType *_Target
	);
};
