#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new NumberType(42);
	auto R2 = new StringType("x");
	auto R3 = ResolveBinding(R2, LE1);
	auto R4 = SimpleAssignmentOperator(R3, R1);
	auto R5 = new StringType("x");
	auto R6 = ResolveBinding(R5, LE1);
	auto R7 = _log(R6);
}
