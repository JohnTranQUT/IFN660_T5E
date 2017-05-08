#pragma once
#include <cstdio>
#include <string>

using namespace std;

class LanguageType {
public:
	virtual ~LanguageType() {};
	virtual string _getType() = 0;
};

//Functions for Language LanguageTyped LanguageTypes(or values)
