#include "RuntimeSemantic.h"
#include "Operation.h"


JSValue* assignment(JSValue* lref, JSValue* rref)
{
	//Assignment Expression: LeftHandSideExpression = AssignmentExpression
	JSValue* rval = GetValue(rref);
	PutValue(lref, rval);
	return rval;
}


