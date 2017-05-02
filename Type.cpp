#include <Type.h>
#include <iostream>
using namespace std;


bool ToBoolean(Type boo)
{
	if (typeid(boo) == typeid(bool)) { return true; }
	else if (typeid(boo) == typeid(int)) { return false; }
};