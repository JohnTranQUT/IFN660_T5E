#include <C:\Users\Administrator\Desktop\rita\SA_ENV\RuntimeLib\Runtime.h>
void main() {
auto r0 = NewDeclEnvi(nullptr);
auto r1 = new NumberType(42);
auto r2 = "x";
auto r3 = ResolveBinding(r2, r0);
auto r4 = AssignmentOperator(r3,r1);
auto r5 = new StringType("IFN");
auto r6 = "y";
auto r7 = ResolveBinding(r6, r0);
auto r8 = AssignmentOperator(r7,r5);
auto r9 = new NumberType(660);
auto r10 = "y";
auto r11 = ResolveBinding(r10, r0);
auto r12 = AdditiveOperator(r11,r9);
auto r13 = "z";
auto r14 = ResolveBinding(r13, r0);
auto r15 = AssignmentOperator(r14,r12);
GetERvalue(r0->getER());
}
