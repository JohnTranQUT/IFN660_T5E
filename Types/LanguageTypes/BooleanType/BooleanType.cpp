#include <Types/LanguageTypes/BooleanType/BooleanType.h>

bool BooleanType::_getValue() const {
	return _value;
}

string BooleanType::_getType() {
	return _type;
}
