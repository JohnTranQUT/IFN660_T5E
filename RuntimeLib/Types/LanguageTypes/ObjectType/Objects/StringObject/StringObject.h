#pragma once
#include "RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h"
#include "RuntimeLib/Types/LanguageTypes/StringType/StringType.h"

class StringObject : public ObjectType {
	LanguageType *value;
public:
	explicit StringObject(LanguageType *_value) : value(_value),
	                                              prototype(this) { }

	class prototype {
		StringObject *string;
	public:
		explicit prototype(StringObject *_string) : string(_string) { }
		StringType *toString() const;
		StringType *valueOf() const;
	} prototype;

	LanguageType *_getValue() const;
};
