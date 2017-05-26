#include "RTLib.h"
int main(){
LexicalEnvironment* lexEnv = NewDeclarativeEnvironment(nullptr);
auto r0 = new NumberValue(42.000000);
auto r1 = "x";
auto r2 = ResolveBinding(r1, lexEnv);
auto r3 = assignment(r2, r0);
auto r4 = new NumberValue(1.000000);
auto r5 = "x";
auto r6 = ResolveBinding(r5, lexEnv);
auto r7 = addition(r6,r4);
auto r8 = "y";
auto r9 = ResolveBinding(r8, lexEnv);
auto r10 = assignment(r9, r7);
}