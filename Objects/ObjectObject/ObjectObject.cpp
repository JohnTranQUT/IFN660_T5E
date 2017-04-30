#include <Objects/ObjectObject/ObjectObject.h>

StringType *ObjectObject::prototype::toString() const {

	// Undefined
	if (dynamic_cast<UndefinedType*>(object->value)) {
		return new StringType("[object Undefined]");
	}

	// Null
	if (dynamic_cast<NullType*>(object->value)) {
		return new StringType("[object Null]");
	}

	// Array

	// String
	if (dynamic_cast<StringType*>(object->value)) {
		return new StringType("[object String]");
	}

	// Arguments

	// Function

	// Error

	// Boolean
	if (dynamic_cast<BooleanType*>(object->value)) {
		return new StringType("[object Boolean]");
	}

	// Number
	if (dynamic_cast<NumberType*>(object->value)) {
		return new StringType("[object Number]");
	}

	// Date

	// RegExp

	// Object
	return new StringType("[object Object]");
}

ObjectType *ObjectObject::prototype::valueOf() {
	// ToObject() not working here due to limitation of C++
	return new ObjectType();
}

LanguageType *ObjectObject::_getValue() const {
	return value;
}

