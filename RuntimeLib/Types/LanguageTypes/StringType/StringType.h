#pragma once
#include <string>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"

using namespace std;

class StringType : public LanguageType {
	string _value;
	string _type = "string";
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};
