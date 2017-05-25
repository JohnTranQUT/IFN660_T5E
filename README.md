# IFN660-T5E Github Repository

## Current Status
Code Generation

## Project Logs

- finish genarate code
- generate the JS code:
- x = 42;
- y = x +1;
- to:
- #include <C:\Users\Administrator\Desktop\rita\SA_ENV\RuntimeLib\Runtime.h>
- void main() {
- auto r0 = NewDeclEnvi(nullptr);
- auto r1 = new NumberType(42);
- auto r2 = "x";
- auto r3 = ResolveBinding(r2, r0);
- auto r4 = AssignmentOperator(r3,r1);
- auto r5 = new NumberType(23);
- auto r6 = "y";
- auto r7 = ResolveBinding(r6, r0);
- auto r8 = AssignmentOperator(r7,r5);
- auto r9 = "y";
- auto r10 = ResolveBinding(r9, r0);
- auto r11 = "x";
- auto r12 = ResolveBinding(r11, r0);
- auto r13 = AdditiveOperator(r12,r10);
- auto r14 = "z";
- auto r15 = ResolveBinding(r14, r0);
- auto r16 = AssignmentOperator(r15,r13);
- }
	