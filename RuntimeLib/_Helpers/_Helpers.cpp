#include <iostream>
#include <RuntimeLib/_Helper/_Helper.h>

void _calculate(LanguageType *lhs, string op, LanguageType *rhs) {
	LanguageType *result = nullptr;
	if (op == "+") {
		result = AdditionOperator(lhs, rhs);
	}
	if (op == "-") {
		result = SubtractionOperator(lhs, rhs);
	}
	if (op == "*") {
		result = MultiplicationOperator(lhs, rhs);
	}
	if (op == "/") {
		result = DivisionOperator(lhs, rhs);
	}
	if (op == "%") {
		result = ModulusOperator(lhs, rhs);
	}
	if (result != nullptr) {
		cout << left << setw(28) << "(" + _GetType(lhs) + ") " + ToString(lhs)->_getValue() << setw(5) << op << setw(28) << "(" + _GetType(rhs) + ") " + ToString(rhs)->_getValue() << setw(5) << "=" << setw(35) << "(" + _GetType(result) + ") " + ToString(result)->_getValue() << endl;
	} else {
		puts("calculate");
		exit(0);
	}
}
