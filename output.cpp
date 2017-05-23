#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new NumberType(0);
	auto R2 = new StringType("x");
	auto R3 = ResolveBinding(R2, LE1);
	auto R4 = SimpleAssignmentOperator(R3, R1);
	auto R5 = ToBoolean(_ToLanguageType(GetValue(R4)));
	if (R5->_getValue()) {
		auto LE2 = NewDeclarativeEnvironment(LE1);
		auto R6 = new NumberType(5);
		auto R7 = new StringType("x");
		auto R8 = ResolveBinding(R7, LE2);
		auto R9 = SimpleAssignmentOperator(R8, R6);
	}
	auto R10 = new StringType("x");
	auto R11 = ResolveBinding(R10, LE1);
	auto R12 = _log(R11);
}
