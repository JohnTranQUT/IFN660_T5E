#pragma once
#include <RuntimeLib\Type\Type.h>
#include <string>

using namespace std;

class BooleanType : public Type {
	bool _value;
	string _type = "Boolean";
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const;
	string _getType() override;
};