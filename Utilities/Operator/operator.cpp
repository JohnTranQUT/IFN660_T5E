#include <iostream>
#include <Types/Types.h>
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Utilities/Operator/Operator.h>

LanguageType *addition(LanguageType *lref, LanguageType *rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lprim = ToPrimitive(lval);
	auto rprim = ToPrimitive(rval);
	if (dynamic_cast<StringType*>(lprim) || dynamic_cast<StringType *>(rprim)) {
		auto lstr = ToString(lprim);
		auto rstr = ToString(rprim);
		auto result = new StringType(lstr + rstr);
		return dynamic_cast<LanguageType *>(result);
	}
	else {
		auto lnum = ToNumber(lprim);
		auto rnum = ToNumber(rprim);
		auto result = new NumberType(lnum + rnum);
		return dynamic_cast<LanguageType *>(result);
	}
}

LanguageType *subtraction(LanguageType *lref, LanguageType *rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lnum = ToNumber(lval);
	auto rnum = ToNumber(rval);
	auto result = new NumberType(lnum - rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *multiplication(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	auto result = new NumberType(lnum * rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *division(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	auto result = new NumberType(lnum / rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *modulus(LanguageType *left, LanguageType *right) {
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue);
	auto rnum = ToNumber(rightValue);
	auto result = new NumberType(fmod(lnum, rnum));
	return dynamic_cast<LanguageType *>(result);
}

void _calculate(LanguageType *lhs, string op, LanguageType *rhs) {
	LanguageType *result = nullptr;
	if (op == "+") {
		result = addition(lhs, rhs);
	}
	if (op == "-") {
		result = subtraction(lhs, rhs);
	}
	if (op == "*") {
		result = multiplication(lhs, rhs);
	}
	if (op == "/") {
		result = division(lhs, rhs);
	}
	if (op == "%") {
		result = modulus(lhs, rhs);
	}
	if (result != nullptr) {
		cout << "(" << _GetType(lhs) << ") " << ToString(lhs) << "\t " << op << " \t(" << _GetType(rhs) << ") " << ToString(rhs) << "\t = \t(" << _GetType(result) << ") " << ToString(result) << endl;
	}
	else {
		puts("calculate");
		exit(0);
	}
}