#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/BooleanObject/BooleanObject.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Objects/NumberObject/NumberObject.h>

BooleanType *thisBooleanValue(LanguageType *value) {
	if (auto _value = dynamic_cast<BooleanType*>(value)) {
		return _value;
	}
	if (dynamic_cast<ObjectType*>(value) && dynamic_cast<BooleanObject*>(value)) {
		auto _value = dynamic_cast<BooleanObject*>(value);
		if (auto boolean = dynamic_cast<BooleanType*>(_value->_getValue())) {
			return boolean;
		}
	}
	puts("TypeError");
	exit(0);
}

StringType *BooleanObject::prototype::toString() const {
	if (thisBooleanValue(boolean->_getValue())->_getValue()) {
		return new StringType("true");
	}
	return new StringType("false");
}

BooleanType *BooleanObject::prototype::valueOf() const {
	return thisBooleanValue(boolean->_getValue());
}

LanguageType *BooleanObject::_getValue() const {
	return value;
}
