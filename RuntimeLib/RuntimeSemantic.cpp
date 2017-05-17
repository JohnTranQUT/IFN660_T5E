#include "RuntimeSemantic.h"
#include "Operation.h"



JSValue* assignment(Type* lref, Type* rref)
{
	//Assignment Expression: LeftHandSideExpression = AssignmentExpression
	JSValue *rval = GetValue(rref);
	PutValue(lref, rval);
	return rval;
}
