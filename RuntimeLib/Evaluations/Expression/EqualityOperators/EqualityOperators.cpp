#include "RuntimeLib/Evaluations/Expression/EqualityOperators/EqualityOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/RuntimeLib.h"

BooleanType *StrictEqualityOperator(Type *lref, Type *rref, BooleanType *invert) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto equal = StrictEqualityComparison(lval, rval);
	if (invert->_getValue()) {
		return new BooleanType(!equal->_getValue());
	}
	return equal;
}

BooleanType *AbstractEqualityOperator(Type *lref, Type *rref, BooleanType *invert) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto equal = AbstractEqualityComparison(lval ,rval);
	if (invert->_getValue()) {
		return new BooleanType(!equal->_getValue());
	}
	return equal;
}