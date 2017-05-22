#include "RuntimeLib/Evaluations/Expression/ExponentOperators/ExponentOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"

LanguageType *ExponentiationOperator(Type *left, Type *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto base = ToNumber(leftValue);
	auto exponent = ToNumber(rightValue);
	return *base ^ *exponent;
}
