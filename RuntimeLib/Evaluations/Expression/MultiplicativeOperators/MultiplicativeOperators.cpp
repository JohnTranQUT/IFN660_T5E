#include <RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h>

LanguageType *MultiplicationOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = *ToNumber(leftValue);
	auto rnum = *ToNumber(rightValue);
	return lnum + rnum;
}

LanguageType *DivisionOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = *ToNumber(leftValue);
	auto rnum = *ToNumber(rightValue);
	return lnum / rnum;
}

LanguageType *ModulusOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = *ToNumber(leftValue);
	auto rnum = *ToNumber(rightValue);
	return lnum % rnum;
}