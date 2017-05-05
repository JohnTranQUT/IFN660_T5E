#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>

using namespace std;

class ObjectType : public LanguageType {
	string _value;
public:
	explicit ObjectType(string value) : _value(value) { };
	string _getValue() const;
};