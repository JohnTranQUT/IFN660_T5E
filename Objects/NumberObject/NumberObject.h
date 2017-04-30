#pragma once
#include <Objects/ObjectObject/ObjectObject.h>
#include <Types/LanguageTypes/LanguageTypesFunc.h>

class NumberObject : public ObjectObject {
public:
	explicit NumberObject(LanguageType *_value) : ObjectObject(_value), prototype(this) {}
	class prototype {
		NumberObject *number;
	public:
		explicit prototype(NumberObject *_number) : number(_number) {}
		StringType *toString(LanguageType *radix = nullptr) const;
		NumberType *valueOf() const;
	} prototype;
};