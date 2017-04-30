#include <operator.h>
#include <iostream>
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