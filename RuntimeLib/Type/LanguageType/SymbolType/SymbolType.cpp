#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <string>
//Not Complete, needs work

using namespace std;

string SymbolType::_getValue() const {
	return _value;
}

string SymbolType::_getType() {
	return _type;
}