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
		if (signbit(lhs._getValue()) && !signbit(rhs._getValue()) || !signbit(lhs._getValue()) && signbit(rhs._getValue())) {
			return new NumberType(NAN);
		}
		if (!signbit(lhs._getValue()) && !signbit(rhs._getValue())) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}
	if (isinf(lhs._getValue())) {
		return new NumberType(lhs._getValue());
	}
	if (isinf(rhs._getValue())) {
		return new NumberType(rhs._getValue());
	}

	feclearexcept(FE_OVERFLOW);

	auto _result = lhs._getValue() + rhs._getValue();

	if (static_cast<bool>(fetestexcept(FE_OVERFLOW))) {
		if (signbit(_result)) {
			return new NumberType(-INFINITY);
		}
		return new NumberType(INFINITY);
	}

	return new NumberType(_result);

}

NumberType *NumberType::operator*(NumberType &rhs) const {
	auto lhs = *this;
	auto _hasSameSign = signbit(lhs._getValue()) == signbit(rhs._getValue());
	if (isnan(lhs._getValue()) || isnan(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue()) && rhs._getValue() == 0 || lhs._getValue() == 0 && isinf(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue()) || isinf(rhs._getValue())) {
		if (_hasSameSign) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}

	feclearexcept(FE_OVERFLOW);

	auto _result = lhs._getValue() * rhs._getValue();

	if (static_cast<bool>(fetestexcept(FE_OVERFLOW))) {
		if (_hasSameSign) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}

	return new NumberType(_result);
}

NumberType *NumberType::operator/(NumberType &rhs) const {
	auto lhs = *this;
	auto _hasSameSign = signbit(lhs._getValue()) == signbit(rhs._getValue());
	if (isnan(lhs._getValue()) || isnan(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue()) && isinf(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue())) {
		if (_hasSameSign) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}
	if (isinf(rhs._getValue())) {
		if (_hasSameSign) {
			return new NumberType(0);
		}
		return new NumberType(-0);
	}
	if (lhs._getValue() == 0) {
		if (rhs._getValue() == 0) {
			return new NumberType(NAN);
		}
		if (_hasSameSign) {
			return new NumberType(0);
		}
		return new NumberType(-0);
	}
	if (rhs._getValue() == 0) {
		if (_hasSameSign) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}

	feclearexcept(FE_OVERFLOW);
	feclearexcept(FE_UNDERFLOW);

	auto _result = lhs._getValue() / rhs._getValue();

	if (static_cast<bool>(fetestexcept(FE_OVERFLOW))) {
		if (_hasSameSign) {
			return new NumberType(INFINITY);
		}
		return new NumberType(-INFINITY);
	}
	if (static_cast<bool>(fetestexcept(FE_UNDERFLOW))) {
		if (_hasSameSign) {
			return new NumberType(0);
		}
		return new NumberType(-0);
	}

	return new NumberType(_result);
}

NumberType *NumberType::operator%(NumberType &rhs) const {
	auto lhs = *this;
	auto _sign = signbit(lhs._getValue());
	if (isnan(lhs._getValue()) || isnan(rhs._getValue())) {
		return new NumberType(NAN);
	}
	if (isinf(lhs._getValue()) || rhs._getValue() == 0) {
		return new NumberType(NAN);
	}
	if (isinf(rhs._getValue())) {
		return new NumberType(rhs._getValue());
	}
	if (lhs._getValue() == 0) {
		return new NumberType(lhs._getValue());
	}

	auto _result = fmod(lhs._getValue(), rhs._getValue());
	return new NumberType(_result);
}
