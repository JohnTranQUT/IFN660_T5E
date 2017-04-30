#include <Objects/BooleanObject/BooleanObject.h>

BooleanType *thisBooleanValue(LanguageType *value) {
	if (auto _value = dynamic_cast<BooleanType*>(value)) {
		return _value;
	}
	if (dynamic_cast<ObjectType*>(value) && dynamic_cast<ObjectObject*>(value)) {
		auto _value = dynamic_cast<ObjectObject*>(value);
		if (auto _boolean = dynamic_cast<BooleanType*>(_value->_getValue())) {
			return _boolean;
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
