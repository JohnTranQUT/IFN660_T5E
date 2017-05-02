#pragma once
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Types/SpecificationTypes/RecordType/RecordType.h>

using namespace std;

class CompletionType : public RecordType {
public:
	explicit CompletionType(
		StringType *_Type,
		LanguageType *_Value,
		StringType *_Target
	);
};
