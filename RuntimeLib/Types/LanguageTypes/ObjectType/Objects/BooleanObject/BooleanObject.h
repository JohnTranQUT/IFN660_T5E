#pragma once
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/LanguageTypes/StringType/StringType.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>

class BooleanObject : public ObjectType {
	LanguageType *value;
public:
	explicit BooleanObject(LanguageType *_value) : value(_value),
	                                               prototype(this) { }

	class prototype {
		BooleanObject *boolean;
	public:
		explicit prototype(BooleanObject *_boolean) : boolean(_boolean) { }
		StringType *toString() const;
		BooleanType *valueOf() const;
	} prototype;

	LanguageType *_getValue() const;
};