#pragma once
#include <RuntimeLib\Type\Type.h>

using namespace std;

class NullType : public Type {
	string _value = "null";
	string _type = "Null";
public:
	explicit NullType() { };
	string _getValue() const;
	string _getType() override;
};