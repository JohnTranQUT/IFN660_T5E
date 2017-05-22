#include "RuntimeLib/Types/LanguageTypes/ObjectType/Objects/NumberObject/NumberObject.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"

NumberType *thisNumberValue(LanguageType *value) {
	if (auto _value = dynamic_cast<NumberType*>(value)) {
		return _value;
	}
	if (dynamic_cast<ObjectType*>(value) && dynamic_cast<NumberObject*>(value)) {
		auto _value = dynamic_cast<NumberObject*>(value);
		if (auto number = dynamic_cast<NumberType*>(_value->_getValue())) {
			return number;
		}
	}
	puts("TypeError");
	exit(0);
}

StringType *NumberObject::prototype::toString(LanguageType *_radix) const {
	auto x = thisNumberValue(number->_getValue());

	if (_radix == nullptr) {
		_radix = new NumberType(10);
	} else if (dynamic_cast<UndefinedType*>(_radix)) {
		_radix = new NumberType(10);
	} else {
		_radix = ToInteger(_radix);
	}

	auto radix = dynamic_cast<NumberType*>(_radix)->_getValue();
	if (radix < 2 || radix > 36) {
		puts("RangeError");
		exit(0);
	}

	if (radix == 10) {
		return ToString(x);
	} else {
		puts("radix != 10");
		exit(0);
	}
}

NumberType *NumberObject::prototype::valueOf() const {
	return thisNumberValue(number->_getValue());
}

LanguageType *NumberObject::_getValue() const {
	return value;
}
