#pragma once
//#include <Types/LanguageTypes/LanguageTypesFunc.h>
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/LanguageTypes/StringType/StringType.h>
#include <Types/LanguageTypes/ObjectType/ObjectType.h>
#include <Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <Types/LanguageTypes/BooleanType/BooleanType.h>
#include <Types/LanguageTypes/NullType/NullType.h>
#include <Types/LanguageTypes/NumberType/NumberType.h>

class ObjectObject : public ObjectType {
	LanguageType *value;
public:
	explicit ObjectObject(LanguageType *_value = new ObjectType()) : value(_value), prototype(this) { }
	class prototype {
		ObjectObject *object;
	public:
		explicit prototype(ObjectObject *_object) : object(_object) {}
		StringType *toString() const;
		static ObjectType *valueOf();
	} prototype;
	LanguageType *_getValue() const;
};