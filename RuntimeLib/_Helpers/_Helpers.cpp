#include <RuntimeLib/_Helpers/_Helpers.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

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

void _listItemsInRecord(RecordType *record) {
	if (auto _record = dynamic_cast<CompletionType *>(record)) {
		auto items = _record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	} else if (auto _record = dynamic_cast<DeclarativeEnvironmentRecord *>(record)) {
		auto items = _record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	} else if (auto _record = dynamic_cast<ObjectEnvironmentRecord *>(record)) {
		auto items = _record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	} else if (auto _record = dynamic_cast<GlobalEnvironmentRecord *>(record)) {
		auto items = _record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	} else if (auto _record = dynamic_cast<EnvironmentRecord *>(record)) {
		auto items = _record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	} else {
		auto items = record->_getValue();
		for (auto it = items.begin(); it != items.end(); ++it) {
			auto items = _record->_getValue();
			cout << it->first->_getValue() << " -> " << ToString(dynamic_cast<LanguageType *>(it->second))->_getValue() << endl;
		}
	}
}
