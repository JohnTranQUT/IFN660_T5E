#pragma once
#include <cstdio>
#include <string>

using namespace std;

class Type {
public:
	virtual ~Type() {};
	virtual string _getType() = 0;
};

//Functions for Language typed Types(or values)
