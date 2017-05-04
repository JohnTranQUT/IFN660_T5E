#pragma once
#include <RuntimeLib/Types/SpecificationTypes/SpecificationTypes.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>

class LexicalEnvironment : public SpecificationType {
	EnvironmentRecord *environmentRecord;
	LexicalEnvironment *outer;
public:
	explicit LexicalEnvironment(
		EnvironmentRecord *_environmentRecord,
		LexicalEnvironment *_outer = nullptr
	) : environmentRecord(_environmentRecord),
	    outer(_outer) { }

	EnvironmentRecord *_getEnvRec() const;
	LexicalEnvironment *_getOuter() const;
};
