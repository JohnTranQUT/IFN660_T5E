#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new StringType("x");
	auto R2 = LE1->_getEnvRec()->CreateMutableBinding(R1, new BooleanType(false));
	auto R3 = new NumberType(42);
	auto R4 = new StringType("x");
	auto R5 = ResolveBinding(R4, LE1);
	auto R6 = InitializeReferencedBinding(R5, R3);
	auto R7 = new NumberType(20);
	auto R8 = new StringType("x");
	auto R9 = ResolveBinding(R8, LE1);
	auto R10 = GreaterThanOperator(R9, R7);
	auto R11 = ToBoolean(_ToLanguageType(GetValue(R10)));
	if (R11->_getValue()) {
		auto LE2 = NewDeclarativeEnvironment(LE1);
		auto R12 = new StringType("x");
		auto R13 = LE2->_getEnvRec()->CreateMutableBinding(R12, new BooleanType(false));
		auto R14 = new NumberType(5);
		auto R15 = new StringType("x");
		auto R16 = ResolveBinding(R15, LE2);
		auto R17 = InitializeReferencedBinding(R16, R14);
		auto R18 = new StringType("x");
		auto R19 = ResolveBinding(R18, LE2);
		auto R20 = _log(R19);
	} else {
		auto LE3 = NewDeclarativeEnvironment(LE1);
		auto R21 = new StringType("y");
		auto R22 = LE3->_getEnvRec()->CreateMutableBinding(R21, new BooleanType(false));
		auto R23 = new NumberType(10);
		auto R24 = new StringType("y");
		auto R25 = ResolveBinding(R24, LE3);
		auto R26 = InitializeReferencedBinding(R25, R23);
		auto R27 = new StringType("y");
		auto R28 = ResolveBinding(R27, LE3);
		auto R29 = _log(R28);
	}
	auto R30 = new StringType("y");
	auto R31 = ResolveBinding(R30, LE1);
	auto R32 = _log(R31);
}
