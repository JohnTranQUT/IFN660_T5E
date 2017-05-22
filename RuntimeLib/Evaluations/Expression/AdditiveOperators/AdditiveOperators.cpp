#include "RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"

LanguageType *AdditionOperator(Type *lref, Type *rref) {
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
	auto lnum = ToNumber(lprim);
	auto rnum = ToNumber(rprim);
	return *lnum + *rnum;
}

LanguageType *SubtractionOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto lnum = ToNumber(lval);
	auto rnum = new NumberType(-ToNumber(rval)->_getValue());
	return *lnum + *rnum;
}
