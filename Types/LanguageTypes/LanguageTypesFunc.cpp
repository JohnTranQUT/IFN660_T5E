#include <Types/LanguageTypes/LanguageTypesFunc.h>

LanguageType *ToPrimitive(LanguageType *input, LanguageType *PreferredType) {
	if (dynamic_cast<ObjectType*>(input)) {
		return nullptr;
	}
	return input;
}

BooleanType *ToBoolean(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return new BooleanType(false);
	}
	if (dynamic_cast<NullType*>(argument)) {
		return new BooleanType(false);
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		return _argument;
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		if (_argument->_getValue() == "") {
			return new BooleanType(false);
		}
		return new BooleanType(true);
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		return new BooleanType(true);
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		auto m = _argument->_getValue();
		if (m == 0 || m == NAN) {
			return new BooleanType(false);
		}
		return new BooleanType(true);
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		return new BooleanType(true);
	}
	puts("ToBoolean");
	exit(0);
}

NumberType *ToNumber(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return new NumberType(NAN);
	}
	if (dynamic_cast<NullType*>(argument)) {
		return new NumberType(0);
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->_getValue()) {
			return new NumberType(1);
		}
		return new NumberType(0);
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return new NumberType(stod(_argument->_getValue()));
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return _argument;
	}
	if (dynamic_cast<ObjectType*>(argument)) {
		puts("Object");
	}
	puts("ToNumber");
	exit(0);
}

NumberType *ToInteger(LanguageType *argument) {
	auto number = ToNumber(argument)->_getValue();
	if (number == NAN) {
		return new NumberType(0);
	}
	return new NumberType(static_cast<int>(floor(number)));
}

StringType *ToString(LanguageType *argument) {
	if (dynamic_cast<UndefinedType*>(argument)) {
		return new StringType("undefined");
	}
	if (dynamic_cast<NullType*>(argument)) {
		return new StringType("null");
	}
	if (auto _argument = dynamic_cast<BooleanType*>(argument)) {
		if (_argument->_getValue()) {
			return new StringType("true");
		}
		return new StringType("false");
	}
	if (auto _argument = dynamic_cast<StringType*>(argument)) {
		return _argument;
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		puts("TypeError");
	}
	if (auto _argument = dynamic_cast<NumberType*>(argument)) {
		return new StringType(to_string(_argument->_getValue()));
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

LanguageType *_ToLanguageType(Type *argument, bool strict) {
	if (auto _argument = dynamic_cast<LanguageType *>(argument)) {
		return _argument;
	}
	if (strict) {
		puts("Interval TypeError (assert LanguageType)");
		exit(0);
	}
	return nullptr;
}
