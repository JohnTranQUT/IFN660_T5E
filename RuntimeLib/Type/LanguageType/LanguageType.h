#pragma once
#include <RuntimeLib\Type\Type.h>
#include <cstdio>
#include <string>

using namespace std;

class LanguageType : public Type{
public:
	virtual ~LanguageType() {};
	string _getType() override;
	friend LanguageType * ToLanguageType(Type *);
};

//Functions for Language LanguageTyped LanguageTypes(or values)
