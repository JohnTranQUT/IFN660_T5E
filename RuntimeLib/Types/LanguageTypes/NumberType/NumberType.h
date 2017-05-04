#pragma once
#include <string>
#include <cmath>
#include <cfenv>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class NumberType : public LanguageType {
	double _value;
	string _type = "number";
public:
	explicit NumberType(double value) : _value(value) { };
	double _getValue() const;
	string _getType() override;
	NumberType *operator+(NumberType &) const;
	NumberType *operator*(NumberType &) const;
	NumberType *operator/(NumberType &) const;
	NumberType *operator%(NumberType &) const;
};
