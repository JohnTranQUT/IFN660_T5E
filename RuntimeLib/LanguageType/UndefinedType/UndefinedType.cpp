#include <RuntimeLib\LanguageType\UndefinedType\UndefinedType.h>

using namespace std;

string UndefinedType::_getValue() const {
	return _value;
}

string UndefinedType::_getType() {
	return _type;
}