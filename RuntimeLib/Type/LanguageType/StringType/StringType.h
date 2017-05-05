#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>

using namespace std;

class StringType : public LanguageType {
	string _value;
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const;
};