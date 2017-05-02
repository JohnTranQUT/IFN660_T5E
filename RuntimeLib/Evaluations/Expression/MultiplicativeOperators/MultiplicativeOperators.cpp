#include <RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h>

LanguageType *MultiplicationOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	auto result = new NumberType(lnum * rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *DivisionOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	auto result = new NumberType(lnum / rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *ModulusOperator(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	auto result = new NumberType(fmod(lnum, rnum));
	return dynamic_cast<LanguageType *>(result);
}