#include <RuntimeLib/Types/LanguageTypes/NumberType/NumberType.h>

double NumberType::_getValue() const {
	return _value;
}

string NumberType::_getType() {
	return _type;
}

NumberType *NumberType::operator+(NumberType &rhs) const {
	auto lhs = *this;
	if (isnan(lhs._getValue()) || isnan(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue()) && isinf(rhs._getValue())) {
		if (0 > lhs._getValue() && 0 < rhs._getValue() || 0 < lhs._getValue() && 0 > rhs._getValue()) {
			return new NumberType(NAN);
		}
		if (0 < lhs._getValue() && 0 < rhs._getValue()) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}
	if (isinf(lhs._getValue())) {
		return &lhs;
	}
	if (isinf(rhs._getValue())) {
		return &rhs;
	}
	auto _result = lhs._getValue() + rhs._getValue();
	if (_result == HUGE_VAL) {
		return new NumberType(INFINITY);
	}
	if (_result == -HUGE_VAL) {
		return new NumberType(-INFINITY);
	}
	return new NumberType(_result);

}

