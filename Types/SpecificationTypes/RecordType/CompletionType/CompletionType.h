#pragma once
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Types/SpecificationTypes/RecordType/RecordType.h>

class CompletionType : public RecordType {
	string Type;
	LanguageType *Value;
	string Target;
public:
	CompletionType(string _Type, LanguageType *_Value, string _Target) : Type(_Type), Value(_Value), Target(_Target) { };
	string _getType() const;
	LanguageType *_getValue() const;
	string _getTarget() const;
};
