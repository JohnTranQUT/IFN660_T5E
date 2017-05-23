#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>

using namespace std;

class NumberType : public LanguageType {
	double _value;
	string _type = "Number";
public:
	explicit NumberType(double value) : _value(value) { };
	double _getValue() const;
	string _getType() override;
};