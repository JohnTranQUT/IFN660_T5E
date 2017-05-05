#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>
#include <string>

using namespace std;

class ReferenceType : public SpecificationType {
	LanguageType* _base; //Works with all except Null Type
	LanguageType* _reference_name;//Only works with StringType and SymbolType
	BooleanType* _strict_reference;
	ReferenceType* _thisValue;
public:
	explicit ReferenceType(LanguageType* base, LanguageType* reference_name, BooleanType* strict_reference, ReferenceType* thisValue)
		: _base(base), _reference_name(reference_name), _strict_reference(strict_reference), _thisValue(thisValue) { };
	LanguageType* GetBase() const;
	LanguageType* GetReferenceName() const;
	BooleanType* IsStrictReference() const;
	BooleanType* HasPrimitiveBase() const;
	BooleanType* IsPropertyReference() const;
	BooleanType* IsUnresolvableReference() const;
	BooleanType* IsSuperReference() const;
};