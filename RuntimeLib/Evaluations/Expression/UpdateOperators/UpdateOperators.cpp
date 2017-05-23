#include "RuntimeLib/Evaluations/Expression/UpdateOperators/UpdateOperators.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h"

NumberType *PostfixIncrementOperator(Type *lhs) {
	auto oldValue = ToNumber(_ToLanguageType(GetValue(lhs)));
	auto newValue = AdditionOperator(oldValue, new NumberType(1));
	PutValue(lhs, newValue);
	return oldValue;
}

NumberType *PostfixDecrementOperator(Type *lhs) {
	auto oldValue = ToNumber(_ToLanguageType(GetValue(lhs)));
	auto newValue = SubtractionOperator(oldValue, new NumberType(1));
	PutValue(lhs, newValue);
	return oldValue;
}

NumberType *PrefixIncrementOperator(Type *expr) {
	auto oldValue = ToNumber(_ToLanguageType(GetValue(expr)));
	auto newValue = AdditionOperator(oldValue, new NumberType(1));
	PutValue(expr, newValue);
	return ToNumber(newValue);
}

NumberType *PrefixDecrementOperator(Type *expr) {
	auto oldValue = ToNumber(_ToLanguageType(GetValue(expr)));
	auto newValue = SubtractionOperator(oldValue, new NumberType(1));
	PutValue(expr, newValue);
	return ToNumber(newValue);
}