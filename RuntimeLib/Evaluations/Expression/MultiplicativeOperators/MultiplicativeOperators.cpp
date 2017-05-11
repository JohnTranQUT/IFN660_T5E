#include <RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h>
#include <RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h>

LanguageType *MultiplicationOperator(Type *left, Type *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return *lnum * *rnum;
}

LanguageType *DivisionOperator(Type *left, Type *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return *lnum / *rnum;
}

LanguageType *ModulusOperator(Type *left, Type *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return *lnum % *rnum;
}
