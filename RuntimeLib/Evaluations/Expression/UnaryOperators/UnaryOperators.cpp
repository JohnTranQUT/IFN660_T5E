#include "RuntimeLib/Evaluations/Expression/UnaryOperators/UnaryOperators.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"

NumberType *UnaryPLUSOperator(Type *expr) {
	return ToNumber(_ToLanguageType(GetValue(expr)));
}

NumberType *UnaryMINUSOperator(Type *expr) {
	auto oldValue = ToNumber(_ToLanguageType(GetValue(expr)));
	if (isnan(oldValue->_getValue())) {
		return new NumberType(NAN);
	}
	return new NumberType(-oldValue->_getValue());
}

BooleanType *LogicalNOTOperator(Type *expr) {
	auto oldValue = ToBoolean(_ToLanguageType(GetValue(expr)));
	return new BooleanType(!oldValue->_getValue());
}