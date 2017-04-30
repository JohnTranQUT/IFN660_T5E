#include <iostream>
#include <Types/LanguageTypes/LanguageTypesFunc.h>
#include <Types/SpecificationTypes/ReferenceType/ReferenceTypeFunc.h>
#include <Utilities/Operator/Operator.h>

LanguageType *addition(LanguageType *lref, LanguageType *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto lprim = ToPrimitive(lval);
	auto rprim = ToPrimitive(rval);
	if (dynamic_cast<StringType *>(lprim) || dynamic_cast<StringType *>(rprim)) {
		auto lstr = ToString(lprim)->_getValue();
		auto rstr = ToString(rprim)->_getValue();
		auto result = new StringType(lstr + rstr);
		return dynamic_cast<LanguageType *>(result);
	}
	auto lnum = ToNumber(lprim)->_getValue();
	auto rnum = ToNumber(rprim)->_getValue();
	auto result = new NumberType(lnum + rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *subtraction(LanguageType *lref, LanguageType *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	auto result = new NumberType(lnum - rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *multiplication(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	auto result = new NumberType(lnum * rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *division(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	auto result = new NumberType(lnum / rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *modulus(LanguageType *left, LanguageType *right) {
	auto leftValue = _ToLanguageType(GetValue(left));
	auto rightValue = _ToLanguageType(GetValue(right));
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
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
		cout << left << setw(28) << "(" + _GetType(lhs) + ") " + ToString(lhs)->_getValue() << setw(5) << op << setw(28) << "(" + _GetType(rhs) + ") " + ToString(rhs)->_getValue() << setw(5) << "=" << setw(35) << "(" + _GetType(result) + ") " + ToString(result)->_getValue() << endl;
	} else {
		puts("calculate");
		exit(0);
	}
}
