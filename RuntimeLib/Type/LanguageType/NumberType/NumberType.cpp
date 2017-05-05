#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <string>

using namespace std;

 double NumberType::_getValue() const {
	return _value;
}

string NumberType::_getType() {
	return _type;
}