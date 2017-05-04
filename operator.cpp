#include <iostream>
#include "operator.h"
#include "AstExpression.h"
#define DEBUG

GeneralType *addition(GeneralType *lref, GeneralType *rref) {

	GeneralType* lval = GetValue(lref);
	GeneralType* rval = GetValue(rref);
	GeneralType* lprim = lval->ToPrimitive();
	GeneralType* rprim = rval->ToPrimitive();
	if (dynamic_cast<String*>(lprim) || dynamic_cast<String *>(rprim)) {
		auto lstr = lprim->ToString();
		auto rstr = rprim->ToString();
		auto result = new String(lstr + rstr);
		dynamic_cast<GeneralType *>(result);
#ifdef DEBUG
		cout << "(" << lprim->_getType() << ") " << lprim->ToString() << "\t " << "+" << " \t(" << rprim->_getType() << ") " << rprim->ToString() << "\t = \t(" << result->_getType() << ") " << result->ToString() << endl;
#endif
		return result;
	}
	else {
		auto lnum = lprim->ToNumber();
		auto rnum = rprim->ToNumber();
		auto result = new Number(lnum + rnum);
		dynamic_cast<GeneralType *>(result);
#ifdef DEBUG
		cout << "(" << lprim->_getType() << ") " << lprim->ToString() << "\t " << "+" << " \t(" << rprim->_getType() << ") " << rprim->ToString() << "\t = \t(" << result->_getType() << ") " << result->ToString() << endl;
#endif
		return result;
	}
}

GeneralType *subtraction(GeneralType *lref, GeneralType *rref) {

	GeneralType* lval = GetValue(lref);
	GeneralType* rval = GetValue(rref);
	GeneralType* lprim = lval->ToPrimitive();
	GeneralType* rprim = rval->ToPrimitive();
	auto lnum = lprim->ToNumber();
	auto rnum = rprim->ToNumber();
	auto result = new Number(lnum - rnum);
	dynamic_cast<GeneralType *>(result);
#ifdef DEBUG
	cout << "(" << lprim->_getType() << ") " << lprim->ToString() << "\t " << "-" << " \t(" << rprim->_getType() << ") " << rprim->ToString() << "\t = \t(" << result->_getType() << ") " << result->ToString() << endl;
#endif
	return result;
}

GeneralType *assignment(GeneralType *lref, GeneralType *rref) {
//AssignmentExpression:LeftHandSideExpression = AssignmentExpression
//	If LeftHandSideExpression is neither an ObjectLiteral nor an ArrayLiteral, then
//	Let lref be the result of evaluating LeftHandSideExpression.
//	ReturnIfAbrupt(lref).
	
//	Let rref be the result of evaluating AssignmentExpression.
//	Let rval be ? GetValue(rref).
//	If IsAnonymousFunctionDefinition(AssignmentExpression) and IsIdentifierRef of LeftHandSideExpression are both true, then
//	Let hasNameProperty be ? HasOwnProperty(rval, "name").
	GeneralType *rval = GetValue(rref);
//	If hasNameProperty is false, perform SetFunctionName(rval, GetReferencedName(lref)).
//	Perform ? PutValue(lref, rval).
//	Return rval.
	PutValue(lref, rval);
//	Let assignmentPattern be the parse of the source text corresponding to LeftHandSideExpression using AssignmentPattern[? Yield] as the goal symbol.
//	Let rref be the result of evaluating AssignmentExpression.
//	Let rval be ? GetValue(rref).

//	Let status be the result of performing DestructuringAssignmentEvaluation of assignmentPattern using rval as the argument.
//	ReturnIfAbrupt(status).
//	Return rval.
	return rval;
}