#pragma once
#include <Types/LanguageTypes/LanguageTypesFunc.h>

class NumberObject : public ObjectType {
	LanguageType *value;
public:
	explicit NumberObject(LanguageType *_value) : value(_value), prototype(this) {}
	class prototype {
		NumberObject *number;
	public:
		explicit prototype(NumberObject *_number) : number(_number) {}
		StringType *toString(LanguageType *radix = nullptr) const;
		NumberType *valueOf() const;
	} prototype;
	LanguageType *_getValue() const;
};