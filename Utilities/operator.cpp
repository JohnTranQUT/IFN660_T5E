#include <iostream>
#include <Types/Types.h>
#include <Types/LanguageTypes.h>
#include <Types/SpecificationTypes.h>
#include <Utilities/operator.h>

ResultContainer *addition(LanguageType *lref, LanguageType *rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lprim = ToPrimitive(lval);
	auto rprim = ToPrimitive(rval);
	if (dynamic_cast<StringType*>(lprim) || dynamic_cast<StringType *>(rprim)) {
		auto lstr = ToString(lprim);
		auto rstr = ToString(rprim);
		return new ResultContainer(lstr + rstr);
	}
	else {
		auto lnum = ToNumber(lprim);
		auto rnum = ToNumber(rprim);
		return new ResultContainer(lnum + rnum);
	}
}

ResultContainer *subtraction(LanguageType *lref, LanguageType *rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lnum = ToNumber(lval);
	auto rnum = ToNumber(rval);
	return new ResultContainer(lnum - rnum);
}

ResultContainer *multiplication(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return new ResultContainer(lnum * rnum);
}

ResultContainer *division(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return new ResultContainer(lnum / rnum);
}

ResultContainer *modulus(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	return new ResultContainer(fmod(lnum, rnum));
}