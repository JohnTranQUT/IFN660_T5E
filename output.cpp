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
	auto R10 = LessThanOperator(R9, R7);
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
		auto R21 = new NumberType(30);
		auto R22 = new StringType("x");
		auto R23 = ResolveBinding(R22, LE1);
		auto R24 = GreaterThanOperator(R23, R21);
		auto R25 = ToBoolean(_ToLanguageType(GetValue(R24)));
		if (R25->_getValue()) {
			auto LE3 = NewDeclarativeEnvironment(LE1);
			auto R26 = new StringType("x");
			auto R27 = LE3->_getEnvRec()->CreateMutableBinding(R26, new BooleanType(false));
			auto R28 = new NumberType(10);
			auto R29 = new StringType("x");
			auto R30 = ResolveBinding(R29, LE3);
			auto R31 = InitializeReferencedBinding(R30, R28);
			auto R32 = new StringType("x");
			auto R33 = ResolveBinding(R32, LE3);
			auto R34 = _log(R33);
		}
	}
	auto R35 = new StringType("x");
	auto R36 = ResolveBinding(R35, LE1);
	auto R37 = _log(R36);
}
