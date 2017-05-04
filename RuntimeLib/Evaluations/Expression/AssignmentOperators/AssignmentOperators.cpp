#include <RuntimeLib/Evaluations/Expression/AssignmentOperators/AssignmentOperators.h>

Type *SimpleAssignmentOperator(Type *lref, Type *rref) {

	// Assume lref !== ObjectLiteral && lref !== ArrayLiteral

	if (auto _lref = dynamic_cast<CompletionType *>(lref)) {
		auto isArruptCompletion = ReturnIfAbrupt(_lref);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		lref = isArruptCompletion;
	}
	if (auto _rref = dynamic_cast<CompletionType *>(rref)) {
		auto isArruptCompletion = ReturnIfAbrupt(_rref);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
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
