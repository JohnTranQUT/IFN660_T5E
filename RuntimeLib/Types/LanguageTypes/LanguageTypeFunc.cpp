#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/LanguageTypes/NullType/NullType.h"
#include "RuntimeLib/Types/LanguageTypes/SymbolType/SymbolType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Objects/ObjectObject/ObjectObject.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Objects/BooleanObject/BooleanObject.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Objects/NumberObject/NumberObject.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Objects/StringObject/StringObject.h"
#include "RuntimeLib/_Helpers/_Helpers.h"

LanguageType *ToPrimitive(LanguageType *input, LanguageType *PreferredType) {
	if (auto _input = dynamic_cast<ObjectType *>(input)) {
		string hint;
		if (PreferredType == nullptr) {
			hint = "default";
		} else if (dynamic_cast<StringType *>(PreferredType)) {
			hint = "string";
		} else {
			hint = "number";
		}

		// exoticToPrim (check Data objects and Symbol objects)

		if (hint == "default") {
			hint = "number";
		}
		return OrdinaryToPrimitive(_input, hint);
	}
	return input;
}

LanguageType *OrdinaryToPrimitive(ObjectType *O, string hint) {
	if (hint == "string") {
		if (auto _O = dynamic_cast<BooleanObject *>(O)) {
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
		} else if (auto _O = dynamic_cast<NumberObject *>(O)) {
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
		} else if (auto _O = dynamic_cast<StringObject *>(O)) {
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
		} else if (auto _O = dynamic_cast<ObjectObject *>(O)) {
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
		}
	} else {
		if (auto _O = dynamic_cast<BooleanObject *>(O)) {
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
		} else if (auto _O = dynamic_cast<NumberObject *>(O)) {
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
		} else if (auto _O = dynamic_cast<StringObject *>(O)) {
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
		} else if (auto _O = dynamic_cast<ObjectObject *>(O)) {
			auto _valueOfResult = _O->prototype.valueOf();
			if (!_CheckIfObject(_valueOfResult)) {
				return _valueOfResult;
			}
			auto _toStringResult = _O->prototype.toString();
			if (!_CheckIfObject(_toStringResult)) {
				return _toStringResult;
			}
		}
	}
	puts("TypeError");
	exit(0);
}

BooleanType *ToBoolean(LanguageType *argument) {
	if (dynamic_cast<UndefinedType *>(argument)) {
		return new BooleanType(false);
	}
	if (dynamic_cast<NullType *>(argument)) {
		return new BooleanType(false);
	}
	if (auto _argument = dynamic_cast<BooleanType *>(argument)) {
		return _argument;
	}
	if (auto _argument = dynamic_cast<StringType *>(argument)) {
		if (_argument->_getValue() == "") {
			return new BooleanType(false);
		}
		return new BooleanType(true);
	}
	if (dynamic_cast<SymbolType*>(argument)) {
		return new BooleanType(true);
	}
	if (auto _argument = dynamic_cast<NumberType *>(argument)) {
		auto m = _argument->_getValue();
		if (m == 0 || isnan(m)) {
			return new BooleanType(false);
		}
		return new BooleanType(true);
	}
	if (dynamic_cast<ObjectType *>(argument)) {
		return new BooleanType(true);
	}
	puts("ToBoolean");
	exit(0);
}

NumberType *ToNumber(LanguageType *argument) {
	if (dynamic_cast<UndefinedType *>(argument)) {
		return new NumberType(NAN);
	}
	if (dynamic_cast<NullType *>(argument)) {
		return new NumberType(0);
	}
	if (auto _argument = dynamic_cast<BooleanType *>(argument)) {
		if (_argument->_getValue()) {
			return new NumberType(1);
		}
		return new NumberType(0);
	}
	if (auto _argument = dynamic_cast<StringType *>(argument)) {
		try {
			auto number = stod(_argument->_getValue());
			return new NumberType(number);
		} catch (const invalid_argument &) {
			return new NumberType(NAN);
		}
	}
	if (dynamic_cast<SymbolType *>(argument)) {
		puts("TypeError");
	}
	if (auto _argument = dynamic_cast<NumberType *>(argument)) {
		return _argument;
	}
	if (dynamic_cast<ObjectType *>(argument)) {
		auto primValue = ToPrimitive(argument, new NumberType(1));
		return ToNumber(primValue);
	}
	puts("ToNumber");
	exit(0);
}

NumberType *ToInteger(LanguageType *argument) {
	auto number = ToNumber(argument)->_getValue();
	if (isnan(number)) {
		return new NumberType(0);
	}
	return new NumberType(static_cast<int>(floor(number)));
}

StringType *ToString(LanguageType *argument) {
	if (dynamic_cast<UndefinedType *>(argument)) {
		return new StringType("undefined");
	}
	if (dynamic_cast<NullType *>(argument)) {
		return new StringType("null");
	}
	if (auto _argument = dynamic_cast<BooleanType *>(argument)) {
		if (_argument->_getValue()) {
			return new StringType("true");
		}
		return new StringType("false");
	}
	if (auto _argument = dynamic_cast<StringType *>(argument)) {
		return _argument;
	}
	if (dynamic_cast<SymbolType *>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (auto _argument = dynamic_cast<NumberType *>(argument)) {
		if (isnan(_argument->_getValue())) {
			return new StringType("NaN");
		}
		if (isinf(_argument->_getValue())) {
			if (0 < _argument->_getValue()) {
				return new StringType("Infinity");
			}
			return new StringType("-Infinity");
		}
		return new StringType(_TrimDecimal(to_string(_argument->_getValue())));
	}
	if (dynamic_cast<ObjectType *>(argument)) {
		auto primValue = ToPrimitive(argument, new StringType(""));
		return ToString(primValue);
	}
	puts("ToString");
	exit(0);
}

ObjectType *ToObject(LanguageType *argument) {
	if (dynamic_cast<UndefinedType *>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (dynamic_cast<NullType *>(argument)) {
		puts("TypeError");
		exit(0);
	}
	if (auto _argument = dynamic_cast<BooleanType *>(argument)) {
		return new BooleanObject(_argument);
	}
	if (auto _argument = dynamic_cast<StringType *>(argument)) {
		return new StringObject(_argument);
	}
	if (dynamic_cast<SymbolType *>(argument)) {
		puts("Symbol");
	}
	if (auto _argument = dynamic_cast<NumberType *>(argument)) {
		return new NumberObject(_argument);
	}
	if (auto _argument = dynamic_cast<ObjectType *>(argument)) {
		return _argument;
	}
	puts("ToObject");
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

bool _CheckIfObject(LanguageType *input) {
	if (dynamic_cast<ObjectType *>(input)) {
		return true;
	}
	return false;
}

string _TrimDecimal(string value) {
	while (value.find(".") != string::npos && value.substr(value.length() - 1, 1) == "0" || value.substr(value.length() - 1, 1) == ".") {
		value.pop_back();
	}
	return value;
}

BooleanType *StrictEqualityComparison(LanguageType *LHS, LanguageType *RHS) {
	if (!_sameType(LHS ,RHS)->_getValue()) {
		return new BooleanType(false);
	}
	if (auto _LHS = dynamic_cast<NumberType *>(LHS)) {
		if (isnan(_LHS->_getValue())) {
			return new BooleanType(false);
		}
		auto _RHS = dynamic_cast<NumberType *>(RHS);
		if (isnan(_RHS->_getValue())) {
			return new BooleanType(false);
		}
		if (_LHS->_getValue() == _RHS->_getValue()) {
			return new BooleanType(true);
		}
		return new BooleanType(false);
	}
	return SameValueNonNumber(LHS, RHS);
}

BooleanType *SameValueNonNumber(LanguageType *LHS, LanguageType *RHS) {
	if (dynamic_cast<UndefinedType *>(LHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<NullType *>(LHS)) {
		return new BooleanType(true);
	}
	if (auto _LHS = dynamic_cast<StringType *>(LHS)) {
		auto _RHS = dynamic_cast<StringType *>(RHS);
		return new BooleanType(_LHS->_getValue() == _RHS->_getValue());
	}
	if (auto _LHS = dynamic_cast<BooleanType *>(LHS)) {
		auto _RHS = dynamic_cast<BooleanType *>(RHS);
		return new BooleanType(_LHS->_getValue() == _RHS->_getValue());
	}
	if (auto _LHS = dynamic_cast<SymbolType *>(LHS)) {
		auto _RHS = dynamic_cast<SymbolType *>(RHS);
		return new BooleanType(_LHS->_getValue() == _RHS->_getValue());
	}
	if (auto _LHS = dynamic_cast<ObjectType *>(LHS)) {
		auto _RHS = dynamic_cast<ObjectType *>(RHS);
		return new BooleanType(_LHS->_getValue() == _RHS->_getValue());
	}
	return new BooleanType(false);
}

BooleanType *AbstractEqualityComparison(LanguageType *LHS, LanguageType *RHS) {
	if (_sameType(LHS, RHS)) {
		return StrictEqualityComparison(LHS, RHS);
	}
	if (dynamic_cast<NullType *>(LHS) && dynamic_cast<UndefinedType *>(RHS) || dynamic_cast<UndefinedType *>(LHS) && dynamic_cast<NullType *> (RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<NumberType *>(LHS) && dynamic_cast<StringType *>(RHS)) {
		return AbstractEqualityComparison(LHS, ToNumber(RHS));
	}
	if (dynamic_cast<StringType *>(LHS) && dynamic_cast<NumberType *>(RHS)) {
		return AbstractEqualityComparison(ToNumber(LHS), RHS);
	}
	if (dynamic_cast<BooleanType *>(LHS)) {
		return AbstractEqualityComparison(ToNumber(LHS), RHS);
	}
	if (dynamic_cast<BooleanType *>(RHS)) {
		return AbstractEqualityComparison(LHS, ToNumber(RHS));
	}
	if ((dynamic_cast<StringType *>(LHS) || dynamic_cast<NumberType *>(LHS) || dynamic_cast<SymbolType *>(LHS)) && dynamic_cast<ObjectType *>(RHS)) {
		return AbstractEqualityComparison(LHS, ToPrimitive(RHS));
	}
	if ((dynamic_cast<StringType *>(RHS) || dynamic_cast<NumberType *>(RHS) || dynamic_cast<SymbolType *>(RHS)) && dynamic_cast<ObjectType *>(LHS)) {
		return AbstractEqualityComparison(ToPrimitive(LHS), RHS);
	}
	return new BooleanType(false);
}