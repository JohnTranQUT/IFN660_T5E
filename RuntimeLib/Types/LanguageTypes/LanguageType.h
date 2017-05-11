#pragma once
#include <string>
#include <RuntimeLib/Types/Type.h>

using namespace std;

class LanguageType : public Type {
public:
	virtual ~LanguageType() { };
	virtual string _getType() = 0;
};
