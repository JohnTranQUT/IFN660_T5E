#include "operator.h"

Type * Operators::addition(Type * lref, Type * rref)
{
	//1. Let lref be the result of evaluating AdditiveExpression.
	//2. Let lval be ? GetValue(lref).
	auto lval = GetValue(lref);
	//3. Let rref be the result of evaluating MultiplicativeExpression.
	//4. Let rval be ? GetValue(rref).
	auto rval = GetValue(rref);
	//5. Let lprim be ? ToPrimitive(lval).
	auto lprim = ToPrimitive(lval);
	//6. Let rprim be ? ToPrimitive(rval).
	auto rprim = ToPrimitive(rval);
	//7. If Type(lprim) is String or Type(rprim) is String, then
	if (dynamic_cast<String*>(lprim) || dynamic_cast<String*>(rprim))
	{
		//	a. Let lstr be ? ToString(lprim).
		string lstr = lprim->to_string();
		//	b. Let rstr be ? ToString(rprim).
		string rstr = rprim->to_string();
		//	c. Return the String that is the result of concatenating lstr and rstr.
		String* result = new String(lstr + rstr);
		return result;
	}
	//8. Let lnum be ? ToNumber(lprim).
 	auto lnum = dynamic_cast<Number*>(lprim->to_number());
	//9. Let rnum be ? ToNumber(rprim).
	auto rnum = dynamic_cast<Number*>(rprim->to_number());

	//10. Return the result of applying the addition operation to lnum and rnum.See the Note below 12.8.5.
	Number* result = new Number();
	result->set(*lnum + *rnum);
	return result;
}
