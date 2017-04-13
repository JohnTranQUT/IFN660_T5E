#include <Types/LanguageTypes/NumberType/NumberType.h>

double NumberType::_getValue() const {
	return _value;
}

string NumberType::_getType() {
	return _type;
}