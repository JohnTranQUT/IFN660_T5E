#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new StringType("x");
	auto R2 = LE1->_getEnvRec()->CreateMutableBinding(R1, new BooleanType(false));
	auto R3 = new NumberType(0);
	auto R4 = new StringType("x");
	auto R5 = ResolveBinding(R4, LE1);
	auto R6 = InitializeReferencedBinding(R5, R3);
	auto R7 = new StringType("x");
	auto R8 = ResolveBinding(R7, LE1);
	auto R9 = LogicalNOTOperator(R8);
	auto R10 = ToBoolean(_ToLanguageType(GetValue(R9)));
	if (R10->_getValue()) {
		auto LE2 = NewDeclarativeEnvironment(LE1);
		auto R11 = new StringType("x");
		auto R12 = ResolveBinding(R11, LE2);
		auto R13 = _log(R12);
	}
	auto R14 = new StringType("x");
	auto R15 = ResolveBinding(R14, LE1);
	auto R16 = _log(R15);
}
