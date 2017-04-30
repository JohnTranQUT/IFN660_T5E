#include <Types/LanguageTypes/NullType/NullType.h>

string NullType::_getValue() const {
	return _value;
}

string NullType::_getType() {
	return _type;
}
