#pragma once
#include <RuntimeLib\Type\Type.h>

using namespace std;

class StringType : public Type {
	string _value;
	string _type = "String";
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};