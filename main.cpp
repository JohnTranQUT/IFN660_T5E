#include <iostream>
#include "RuntimeLib/JSValue.h"
#include "RuntimeLib/Operator.h"

int main() {
	JSNumber* js_number = new JSNumber(3);
	JSBoolean* js_bool = new JSBoolean(true);
	
	JSValue* result = addition(js_number, js_bool);
	std::cout << result->ToString()<<"\n";

}
