#pragma once
#include <Type.h>
#include <iostream>
#include <string>


using namespace std;
Type * addition(Type *, Type *);
Type * get_value(Type * );
Type * ToPrimitive(Type *);
double  ToNumber(Type * argu);
bool  ToBoolean(Type * argu);
string ToString(Type * argu);