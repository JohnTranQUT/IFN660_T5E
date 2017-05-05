#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

using namespace std;

class BooleanType : public LanguageType {
	bool _value;
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const;
};