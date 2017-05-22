#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new StringType("x");
	auto R2 = LE1->_getEnvRec()->CreateMutableBinding(R1, new BooleanType(false));
	auto R3 = new StringType("y");
	auto R4 = LE1->_getEnvRec()->CreateMutableBinding(R3, new BooleanType(false));
	auto R5 = new StringType("x");
	auto R6 = ResolveBinding(R5, LE1);
	auto R7 = InitializeReferencedBinding(R6, new UndefinedType());
	auto R8 = new NullType();
	auto R9 = new StringType("y");
	auto R10 = ResolveBinding(R9, LE1);
	auto R11 = InitializeReferencedBinding(R10, R8);
	auto R12 = new StringType("x");
	auto R13 = ResolveBinding(R12, LE1);
	auto R14 = ToBoolean(_ToLanguageType(GetValue(R13)));
	if (R14->_getValue()) {
		auto LE2 = NewDeclarativeEnvironment(LE1);
		auto R15 = new StringType("y");
		auto R16 = LE2->_getEnvRec()->CreateMutableBinding(R15, new BooleanType(false));
		auto R17 = new StringType("IFN");
		auto R18 = new StringType("y");
		auto R19 = ResolveBinding(R18, LE2);
		auto R20 = InitializeReferencedBinding(R19, R17);
		auto R21 = new StringType("x");
		auto R22 = ResolveBinding(R21, LE2);
		auto R23 = new StringType("y");
		auto R24 = ResolveBinding(R23, LE2);
		auto R25 = new StringType("y + x = ");
		auto R26 = AdditionOperator(R25, R24);
		auto R27 = AdditionOperator(R26, R22);
		auto R28 = _log(R27);
	} else {
		auto LE3 = NewDeclarativeEnvironment(LE1);
		auto R29 = new StringType("x");
		auto R30 = LE3->_getEnvRec()->CreateMutableBinding(R29, new BooleanType(false));
		auto R31 = new StringType("y");
		auto R32 = LE3->_getEnvRec()->CreateMutableBinding(R31, new BooleanType(false));
		auto R33 = new NumberType(660);
		auto R34 = new StringType("x");
		auto R35 = ResolveBinding(R34, LE3);
		auto R36 = InitializeReferencedBinding(R35, R33);
		auto R37 = new StringType("IFN");
		auto R38 = new StringType("y");
		auto R39 = ResolveBinding(R38, LE3);
		auto R40 = InitializeReferencedBinding(R39, R37);
		auto R41 = new StringType("x");
		auto R42 = ResolveBinding(R41, LE3);
		auto R43 = new StringType("y");
		auto R44 = ResolveBinding(R43, LE3);
		auto R45 = new StringType("y + x = ");
		auto R46 = AdditionOperator(R45, R44);
		auto R47 = AdditionOperator(R46, R42);
		auto R48 = _log(R47);
	}
	auto R49 = new StringType("x");
	auto R50 = ResolveBinding(R49, LE1);
	auto R51 = new StringType("x = ");
	auto R52 = AdditionOperator(R51, R50);
	auto R53 = _log(R52);
	auto R54 = new StringType("y");
	auto R55 = ResolveBinding(R54, LE1);
	auto R56 = new StringType("y = ");
	auto R57 = AdditionOperator(R56, R55);
	auto R58 = _log(R57);
}
