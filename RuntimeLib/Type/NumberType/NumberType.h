#pragma once
#include <RuntimeLib\Type\Type.h>

using namespace std;

class NumberType : public Type {
	double _value;
	string _type = "Number";
public:
	explicit NumberType(double value) : _value(value) { };
	double _getValue() const;
	string _getType() override;
};