#include <Type.h>
#include <iostream>
#include <string>
using namespace std;



double Number::VALUE()
{
	return numbervalue;
}

string String::VALUE()
{
	return stringvalue;
}

bool Boolean::VALUE()
{
	return boolvalue;
}
