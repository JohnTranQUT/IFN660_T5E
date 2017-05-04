#pragma once
#include <string>
#include <RuntimeLib/Types/Types.h>

using namespace std;

class LanguageType : public Type {
public:
	virtual ~LanguageType() { };
	virtual string _getType() = 0;
};
