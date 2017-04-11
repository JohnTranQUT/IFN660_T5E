#include <cstdio>
#include <string>
#include <math.h>
#include <LanguageTypes.h>

using namespace std;

bool BooleanType::getValue() const {
	return value;
}

double NumberType::getValue() const {
	return value;
}

string StringType::getValue() const {
	return value;
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
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		return _argument->getValue();
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		auto m = _argument->getValue();
		if (m == 0 || m == NAN) {
			return false;
		}
		return true;
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		if (_argument->getValue() == "") {
			return false;
		}
		return true;
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		return true;
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		return true;
	}
	exit(0);
}

double ToNumber(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return NAN;
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->getValue()) {
			return 1;
		}
		return 0;
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return _argument->getValue();
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return stod(_argument->getValue());
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		puts("Object");
	}
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
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->getValue()) {
			return "true";
		}
		return "false";
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return to_string(_argument->getValue());
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return _argument->getValue();
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		puts("Object");
	}
	exit(0);
}

ObjectType *ToObject(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (dynamic_cast<BooleanType*>(argument)) {
		puts("Boolean");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		puts("Number");
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		puts("String");
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("Symbol");
	}
	if (auto _argument = dynamic_cast<ObjectType*>(argument)) {
		return _argument;
	}
	exit(0);
}