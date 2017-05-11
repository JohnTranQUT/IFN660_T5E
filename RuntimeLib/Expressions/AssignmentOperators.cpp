#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Expressions\AssignmentOperators.h>
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

Type* AssignmentOperator(Type* lref, Type* rref) {
	//1.If LeftHandSideExpression is neither an ObjectLiteral nor an ArrayLiteral,
	//2.Let assignmentPattern be the parse of the source text corresponding to LeftHandSideExpression using AssignmentPattern[? Yield] as the goal symbol.
	//3.Let rref be the result of evaluating AssignmentExpression.
	auto rval = GetValue(rref);
	//5.Let status be the result of performing DestructuringAssignmentEvaluation of assignmentPattern using rval as the argument.
	//ReturnIfAbrupt(status);
	return rval;
}
	