#pragma once
#include <cstdio>
#include <string>
#include <RuntimeLib\Type\Type.h>

using namespace std;

class LanguageType : public Type {
public:
	virtual ~LanguageType() {};
	virtual string _getType() = 0;
};
