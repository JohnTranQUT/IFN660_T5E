#include "RuntimeLib/_Helpers/_Helpers.h"
#include <iostream>
#include <iomanip>
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"
#include "RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h"
#include "RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h"
#include "RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/LanguageTypes/NullType/NullType.h"
#include "RuntimeLib/Types/LanguageTypes/SymbolType/SymbolType.h"

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

BooleanType *_sameType(LanguageType *LHS, LanguageType *RHS) {
	if (dynamic_cast<UndefinedType *>(LHS) && dynamic_cast<UndefinedType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<NullType *>(LHS) && dynamic_cast<NullType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<BooleanType *>(LHS) && dynamic_cast<BooleanType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<StringType *>(LHS) && dynamic_cast<StringType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<SymbolType *>(LHS) && dynamic_cast<SymbolType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<ObjectType *>(LHS) && dynamic_cast<ObjectType *>(RHS)) {
		return new BooleanType(true);
	}
	if (dynamic_cast<NumberType *>(LHS) && dynamic_cast<NumberType *>(RHS)) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

CompletionRecord *_log(Type *type) {
	auto value = ToString(_ToLanguageType(GetValue(type)));
	cout << value->_getValue() << endl;
	return nullptr;
}