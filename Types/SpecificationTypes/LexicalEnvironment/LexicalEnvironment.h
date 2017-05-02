#pragma once
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>

class LexicalEnrivonment : public SpecificationType {
	EnvironmentRecord *environmentRecord;
	LexicalEnrivonment *outer;
public:
	explicit LexicalEnrivonment(EnvironmentRecord *_environmentRecord, LexicalEnrivonment *_outer = nullptr) : environmentRecord(_environmentRecord), outer(_outer) { }
};