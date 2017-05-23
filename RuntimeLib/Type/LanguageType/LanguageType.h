#pragma once
#include <RuntimeLib\Type\Type.h>
#include <cstdio>
#include <string>

using namespace std;

class LanguageType : public Type{
public:
	virtual ~LanguageType() {};
	string _getType() override;
};

LanguageType * ToLanguage(Type *);
//Functions for Language LanguageTyped LanguageTypes(or values)
