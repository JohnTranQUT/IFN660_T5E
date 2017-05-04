#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <typeinfo>
//#include <Type.h>
#include "..\..\IFN660_T5E\operator.h"
//#include <parser.h>

//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
	//	fopen_s(&yyin, argv[1], "r");
	//	yyparse();
	String* _string1 = new String(string("string1"));
	String* _string2 = new String(string("string2"));
	Number* notANumber = new Number(0, true, true);
	Number* zero = new Number(0);
	Number* normalNumber = new Number(123);
	Number* largeNumber = new Number(1.6976931348623157e+308);
	Boolean* _boolean = new Boolean(true);

	//String + String = String
	Type* str_plus_str_test = Operators::addition(_string1, _string2);
	String* str_plus_str_test_cast = dynamic_cast<String*>(str_plus_str_test);
	printf("string plus string test: %s\n", str_plus_str_test_cast->to_string().c_str());
	
	//String + Number = String
	Type* str_plus_number_test = Operators::addition(_string1, normalNumber);
	String* str_plus_number_test_cast = dynamic_cast<String*>(str_plus_number_test);
	printf("string plus number test: %s\n", str_plus_number_test_cast->to_string().c_str());

	//Bool + Number = String
	Type* bool_plus_number_test = Operators::addition(_boolean, _string1);
	String* bool_plus_number_test_cast = dynamic_cast<String*>(bool_plus_number_test);
	printf("bool plus number test: %s\n", bool_plus_number_test_cast->to_string().c_str());

	//Number + Number = Number
	Type* number_plus_number_test = Operators::addition(normalNumber, normalNumber);
	Number* number_plus_number_test_cast = dynamic_cast<Number*>(number_plus_number_test);
	printf("Number plus number test: %s\n", number_plus_number_test_cast->to_string().c_str());

	//large Number + large Number = Infinity
	Type* infinity_test = Operators::addition(largeNumber, largeNumber);
	Number* infinity_test_cast = dynamic_cast<Number*>(infinity_test);
	printf("infinity test: %s\n", infinity_test_cast->to_string().c_str());

	//NaN + large Number = NaN
	Type* NaN_test = Operators::addition(notANumber, largeNumber);
	Number* NaN_test_cast = dynamic_cast<Number*>(NaN_test);
	printf("NaN test: %s\n", NaN_test_cast->to_string().c_str());

	//
}
