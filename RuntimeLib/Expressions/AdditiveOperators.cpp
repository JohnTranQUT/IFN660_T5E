#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>

//Evaluation Functions

LanguageType* additiveOperator(LanguageType* lref, LanguageType* rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lprim = ToPrimitive(lval);
	auto rprim = ToPrimitive(rval);
	if (dynamic_cast<StringType *>(lprim) || dynamic_cast<StringType *>(rprim)) {
		string lstr = (ToString(lprim))->_getValue();
		string rstr = (ToString(rprim))->_getValue();
		return new StringType(lstr + rstr);
	}
	auto lnum = ToNumber(lprim)->_getValue();
	auto rnum = ToNumber(rprim)->_getValue();
	return new NumberType(lnum + rnum);
}

LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	return new NumberType(lnum - rnum);
}