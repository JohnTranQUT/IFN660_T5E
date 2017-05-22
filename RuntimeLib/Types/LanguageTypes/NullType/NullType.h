#pragma once
#include <string>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"

using namespace std;

class NullType : public LanguageType {
	string _value = "null";
	string _type = "object";
public:
	NullType() { };
	string _getValue() const;
	string _getType() override;
};
