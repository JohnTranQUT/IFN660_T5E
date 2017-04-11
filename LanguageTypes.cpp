#include <cstdio>
#include <string>
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

string ToString(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return "undefined";
	}
	if (dynamic_cast<BooleanType*>(argument)) {
		if (argument->getValue()) {
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