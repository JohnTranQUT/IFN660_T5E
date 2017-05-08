#include <RuntimeLib\LanguageType\NullType\NullType.h>

using namespace std;

string NullType::_getValue() const {
	return _value;
}

string NullType::_getType() {
	return _type;
}