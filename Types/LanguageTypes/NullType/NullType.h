#pragma once

#include <string>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class NullType : public LanguageType {
	string _value = "null";
	string _type = "object";
public:
	NullType() { };
	string _getValue() const;
	string _getType() override;
};
