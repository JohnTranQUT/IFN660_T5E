#include "RuntimeLib/SpecificationType/LexicalEnvironment.h"
#include "RuntimeLib/RuntimeSemantic.h"
#include "RuntimeLib/Operation.h"
#include <iostream>
int main(int argc, char* argv[])
{
LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);
Type* r0 = ResolveBinding("x", lexEnv);
Type* r1 = new NumberValue(42.000000);
Type* r3 = assignment(r0,r2);
Type* r4 = ResolveBinding("y", lexEnv);
Type* r5 = ResolveBinding("x", lexEnv);
Type* r7 = new NumberValue(1.000000);
Type* r9 = addition(r6,r8);
Type* r10 = assignment(r4,r9);
std::cout << dynamic_cast<JSValue*>(r10)->ToString();
}
