#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

using namespace std;

class UndefinedType : public LanguageType {
	string _value;
public:
	explicit UndefinedType(string value) : _value(value) { };
	string _getValue() const;
};