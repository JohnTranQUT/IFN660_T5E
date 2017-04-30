#pragma once
#include <Objects/ObjectObject/ObjectObject.h>

class StringObject : public ObjectObject {
public:
	explicit StringObject(LanguageType *_value) : ObjectObject(_value), prototype(this) {}
	class prototype {
		StringObject *string;
	public:
		explicit prototype(StringObject *_string) : string(_string) {}
		StringType *toString() const;
		StringType *valueOf() const;
	} prototype;
};