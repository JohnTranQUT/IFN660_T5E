#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <string>

using namespace std;

string StringType::_getValue() const {
	return _value;
}