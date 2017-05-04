<<<<<<< HEAD
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <RuntimeLib\Type\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\NullType\NullType.h>
#include <RuntimeLib\Type\NumberType\NumberType.h>
#include <RuntimeLib\Type\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\StringType\StringType.h>
#include <RuntimeLib\Type\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\UndefinedType\UndefinedType.h>

#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>

//#include <parser.h>
//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
	auto temp = additiveOperator(new NumberType(1), new NumberType(2));
	auto _temp = dynamic_cast<NumberType *>(temp);
	puts(to_string(_temp->_getValue()));
	puts(_temp->_getType());
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
//	addition();
}
=======
#define _CRT_SECURE_NO_DEPRECATE
#include <Type.h>
#include <operator.h>
#include <math.h>
#include <string>
#include <iostream>
//#include <parser.h>

#define AST 
#define SA

//extern FILE *yyin;
//using namespace std;


void main(int argc, char *argv[]) {
/*
#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
#endif
*/
#ifdef SA
	
	Number * x = new Number(+0);
	Number * y = new Number(-32);
	String * a = new String("little");
	String * b = new String("progress"); 
	Symbol * c = new Symbol();
	String * d = new String("");
	addition(x, y);
	addition(a, b);
	addition(x, a);
	addition(b, y);
	ToBoolean(c);
	ToBoolean(d);

#endif
}
>>>>>>> ray-sa
