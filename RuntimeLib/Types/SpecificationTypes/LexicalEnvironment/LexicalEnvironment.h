#pragma once
#include <RuntimeLib/Types/SpecificationTypes/SpecificationTypes.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>

class LexicalEnrivonment : public SpecificationType {
	EnvironmentRecord *environmentRecord;
	LexicalEnrivonment *outer;
public:
	explicit LexicalEnrivonment(
		EnvironmentRecord *_environmentRecord,
		LexicalEnrivonment *_outer = nullptr
	) : environmentRecord(_environmentRecord),
	    outer(_outer) { }
	ReferenceType *GetIdentifierReference(LexicalEnrivonment *, StringType *, BooleanType *) const;
};
