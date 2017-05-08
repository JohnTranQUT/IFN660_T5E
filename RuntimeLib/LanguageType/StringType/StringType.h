#pragma once
#include <RuntimeLib\LanguageType\LanguageType.h>

using namespace std;

class StringType : public LanguageType {
	string _value;
	string _type = "String";
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};