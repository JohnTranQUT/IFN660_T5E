#pragma once
//#include <RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h>

class ObjectObject : public ObjectType {
	LanguageType *value;
public:
	explicit ObjectObject(LanguageType *_value = new ObjectType()) : value(_value),
	                                                                 prototype(this) { }

	class prototype {
		ObjectObject *object;
	public:
		explicit prototype(ObjectObject *_object) : object(_object) {}
		StringType *toString() const;
		ObjectType *valueOf() const;
	} prototype;

	LanguageType *_getValue() const;
};
