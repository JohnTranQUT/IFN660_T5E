#pragma once
#include <Objects/ObjectObject/ObjectObject.h>

class BooleanObject : public ObjectObject {
public:
	explicit BooleanObject(LanguageType *_value) : ObjectObject(_value), prototype(this) {}
	class prototype {
		BooleanObject *boolean;
	public:
		explicit prototype(BooleanObject *_boolean) : boolean(_boolean) {}
		StringType *toString() const;
		BooleanType *valueOf() const;
	} prototype;
};