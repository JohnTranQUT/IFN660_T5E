#pragma once
#include "RuntimeLib/Types/SpecificationTypes/SpecificationType.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h"

class Reference : public SpecificationType {
	Type *Base;
	LanguageType *Referenced;
	BooleanType *StrictReference;
	ObjectType *thisValue;
public:
	Reference(
		Type *_Base,
		LanguageType *_Referenced,
		BooleanType *_StrictReference,
		ObjectType *_thisValue = nullptr
	) : Base(_Base),
	    Referenced(_Referenced),
	    StrictReference(_StrictReference),
	    thisValue(_thisValue) { };
	Type *GetBase() const;
	LanguageType *GetReferencedName() const;
	BooleanType *IsStrictReference() const;
	BooleanType *HasPrimitiveBase() const;
	BooleanType *IsPropertyReference() const;
	BooleanType *IsUnresolvableReference() const;
	BooleanType *IsSuperReference() const;
	ObjectType *_getThisValue() const;
};
