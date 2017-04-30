#pragma once
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Types/LanguageTypes/LanguageTypesFunc.h>

class ReferenceType : public SpecificationType {
	LanguageType *Base;
	LanguageType *Referenced;
	bool StrictReference;
	ObjectType *thisValue;
public:
	ReferenceType(LanguageType *_Base, LanguageType *_Referenced, bool _StrictReference, ObjectType *_thisValue = nullptr) : Base(_Base),
	                                                                                                                         Referenced(_Referenced),
	                                                                                                                         StrictReference(_StrictReference),
	                                                                                                                         thisValue(_thisValue) { };

	LanguageType *GetBase() const;

	LanguageType *GetReference() const;

	bool IsStrictReference() const;

	bool HasPrimitiveBase() const;

	bool IsPropertyReference() const;

	bool IsUnresolvableReference() const;

	bool IsSuperReference() const;
};
