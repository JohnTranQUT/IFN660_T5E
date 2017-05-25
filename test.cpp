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
std::cout << dynamic_cast<JSValue*>(r3)->ToString();
}
