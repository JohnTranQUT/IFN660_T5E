#include "RuntimeLib/_Helpers/_Helpers.h"
#include <iostream>
#include <iomanip>
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"
#include "RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h"
#include "RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"

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
		cout << left << setw(28) << "(" + lhs->_getType() + ") " + ToString(lhs)->_getValue() << setw(5) << op << setw(28) << "(" + rhs->_getType() + ") " + ToString(rhs)->_getValue() << setw(5) << "=" << setw(35) << "(" + result->_getType() + ") " + ToString(result)->_getValue() << endl;
	} else {
		puts("calculate");
		exit(0);
	}
}

void _listItemsInRecord(Record *record) {
	auto items = record->_getValue();
	for (auto it = items.begin(); it != items.end(); ++it) {
		cout << "\t" << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
	}
}

CompletionRecord *_log(Type *type) {
	auto value = ToString(_ToLanguageType(GetValue(type)));
	cout << value->_getValue() << endl;
	return nullptr;
}