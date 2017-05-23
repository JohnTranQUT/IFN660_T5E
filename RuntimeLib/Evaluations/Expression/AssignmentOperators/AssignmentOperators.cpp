#include "RuntimeLib/Evaluations/Expression/AssignmentOperators/AssignmentOperators.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h"
#include "RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h"
#include "RuntimeLib/Evaluations/Expression/ExponentOperators/ExponentOperators.h"

Type *SimpleAssignmentOperator(Type *lref, Type *rref) {

	// Assume lref !== ObjectLiteral && lref !== ArrayLiteral

	if (auto _lref = dynamic_cast<CompletionRecord *>(lref)) {
		auto isArruptCompletion = ReturnIfAbrupt(_lref);
		if (dynamic_cast<CompletionRecord *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		lref = isArruptCompletion;
	}
	if (auto _rref = dynamic_cast<CompletionRecord *>(rref)) {
		auto isArruptCompletion = ReturnIfAbrupt(_rref);
		if (dynamic_cast<CompletionRecord *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		rref = isArruptCompletion;
	}
	auto rval = GetValue(rref);

	// If IsAnonymousFunctionDefinition(AssignmentExpression) and IsIdentifierRef of LeftHandSideExpression are both true, then
	//     Let hasNameProperty be ? HasOwnProperty(rval, "name").
	//     If hasNameProperty is false, perform SetFunctionName(rval, GetReferencedName(lref)).
	PutValue(lref, rval);
	return rval;
}

Type *CompoundAssignmentOperator(Type *lref, string op, Type *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	LanguageType *r = nullptr;
	if (op == "+") {
		r = AdditionOperator(lval, rval);
		PutValue(lref, r);
	} else if (op == "-") {
		r = SubtractionOperator(lval, rval);
	} else if (op == "*") {
		r = MultiplicationOperator(lval, rval);
	} else if (op == "%") {
		r = ModulusOperator(lval, rval);
	} else if (op == "/") {
		r = DivisionOperator(lval, rval);
	} else if (op == "**") {
		r = ExponentiationOperator(lval, rval);
	}
	PutValue(lref, r);
	return r;
}