#include <cstdio>
#include <string>
#include <math.h>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

string UndefinedType::_getValue() const {
	return _value;
}

string UndefinedType::_getType() {
	return _type;
}

string NullType::_getValue() const {
	return _value;
}

string NullType::_getType() {
	return _type;
}

bool BooleanType::_getValue() const {
	return _value;
}

string BooleanType::_getType() {
	return _type;
}

string StringType::_getValue() const {
	return _value;
}

string StringType::_getType() {
	return _type;
}

string SymbolType::_getValue() const {
	return _value;
}

string SymbolType::_getType() {
	return _type;
}

double NumberType::_getValue() const {
	return _value;
}

string NumberType::_getType() {
	return _type;
}

string ObjectType::_getValue() const {
	return _value;
}

string ObjectType::_getType() {
	return _type;
}

LanguageType *ToPrimitive(LanguageType *input, LanguageType *PreferredType) {
	if (dynamic_cast<ObjectType*>(input)) {
		return nullptr;
	}
	return input;
}

bool ToBoolean(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return false;
	}
	if (dynamic_cast<NullType*>(argument)) {
		return false;
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		return _argument->_getValue();
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		if (_argument->_getValue() == "") {
			return false;
		}
		return true;
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		return true;
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		auto m = _argument->_getValue();
		if (m == 0 || m == NAN) {
			return false;
		}
		return true;
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		return true;
	}
	puts("ToBoolean");
	exit(0);
}

double ToNumber(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return NAN;
	}
	if (dynamic_cast<NullType*>(argument)) {
		return 0;
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->_getValue()) {
			return 1;
		}
		return 0;
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return stod(_argument->_getValue());
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return _argument->_getValue();
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		puts("Object");
	}
	puts("ToNumber");
	exit(0);
}

int ToInteger(LanguageType *argument) {
	auto number = ToNumber(argument);
	if (number == NAN) {
		return 0;
	}
	return static_cast<int>(floor(number));
}

string ToString(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return "undefined";
	}
	if (dynamic_cast<NullType*>(argument)) {
		return "null";
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->_getValue()) {
			return "true";
		}
		return "false";
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return _argument->_getValue();
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return to_string(_argument->_getValue());
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		puts("Object");
	}
	puts("ToString");
	exit(0);
}

ObjectType *ToObject(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (dynamic_cast<NullType*>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (dynamic_cast<BooleanType*>(argument)) {
		puts("Boolean");
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		puts("String");
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("Symbol");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		puts("Number");
	}
	if (auto _argument = dynamic_cast<ObjectType*>(argument)) {
		return _argument;
	}
	puts("ToObject");
	exit(0);
}

string _GetType(LanguageType *argument) {
	if (auto _argument = dynamic_cast<UndefinedType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<NullType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<SymbolType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return _argument->_getType();
	}
	if (auto _argument = dynamic_cast<ObjectType*>(argument)) {
		return _argument->_getType();
	}
	puts("_GetType");
	exit(0);
}