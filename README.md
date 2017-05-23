# IFN660-T5E Github Repository



## Project Logs

-finish genarate code 
-generate the JS code: 
		x = 42;
		y = x +1;

 to:
		#include <C:\Users\Administrator\Desktop\rita\SA_ENV\RuntimeLib\Runtime.h>
		void main() {
		auto r0 = NewDeclEnvi(nullptr);									
		auto r1 = "x";														
		auto r2 = ResolveBinding(r1, r0);								
		auto r3 = new NumberType(42);										
		auto r4 = AssignmentOperator(r2, r3);
		auto r5 = "y";														
		auto r6 = ResolveBinding(r5, r0);						
		auto r7 = "x";														
		auto r8 = ResolveBinding(r7, r0);
		auto r9 = new NumberType(1);										
		auto r10 = AdditiveOperator(r8, r9);									
		auto r11 = AssignmentOperator(r6, r10);	
		}


	