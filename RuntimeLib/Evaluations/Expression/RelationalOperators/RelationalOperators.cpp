#include "RuntimeLib/Evaluations/Expression/RelationalOperators/RelationalOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"

BooleanType *LessThanOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto r = AbstractRelationalComparison(lval, rval);
	return ToBoolean(r);
}

BooleanType *GreaterThanOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto r = AbstractRelationalComparison(rval, lval, new BooleanType(false));
	return ToBoolean(r);
}

BooleanType *LessEqualOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto r = AbstractRelationalComparison(rval, lval, new BooleanType(false));
	if (dynamic_cast<UndefinedType *>(r)) {
		return new BooleanType(false);
	}
	return new BooleanType(!ToBoolean(r)->_getValue());
}

BooleanType *GreaterEqualOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto r = AbstractRelationalComparison(lval, rval);
	if (dynamic_cast<UndefinedType *>(r)) {
		return new BooleanType(false);
	}
	return new BooleanType(!ToBoolean(r)->_getValue());
}
