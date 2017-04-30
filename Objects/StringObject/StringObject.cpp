#include <Objects/StringObject/StringObject.h>

StringType *thisStringValue(LanguageType *value) {
	if (auto _value = dynamic_cast<StringType*>(value)) {
		return _value;
	}
	if (dynamic_cast<ObjectType*>(value) && dynamic_cast<StringObject*>(value)) {
		auto _value = dynamic_cast<StringObject*>(value);
		if (auto string = dynamic_cast<StringType*>(_value->_getValue())) {
			return string;
		}
	}
	puts("TypeError");
	exit(0);
}

StringType *StringObject::prototype::toString() const {
	return thisStringValue(string->_getValue());
}

StringType *StringObject::prototype::valueOf() const {
	return thisStringValue(string->_getValue());
}

LanguageType *StringObject::_getValue() const {
	return value;
}
