#include "RuntimeLib/Evaluations/Expression/BinaryLogicalOperators/BinaryLogicalOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"

Type *LogicalANDOperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto lbool = ToBoolean(lval);
	if (!lbool->_getValue()) {
		return lval;
	}
	return GetValue(rref);
}

Type *LogicalOROperator(Type *lref, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto lbool = ToBoolean(lval);
	if (lbool->_getValue()) {
		return lval;
	}
	return GetValue(rref);
}