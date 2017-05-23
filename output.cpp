#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new BooleanType(false);
	auto R2 = new BooleanType(true);
	auto R3 = LogicalANDOperator(R2, R1);
	auto R4 = ToBoolean(_ToLanguageType(GetValue(R3)));
	if (R4->_getValue()) {
		auto LE2 = NewDeclarativeEnvironment(LE1);
		auto R5 = new NumberType(1);
		auto R6 = _log(R5);
	}
	auto R7 = new NumberType(2);
	auto R8 = _log(R7);
}
