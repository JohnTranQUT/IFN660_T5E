#pragma once
#include <RuntimeLib\Type\Type.h>
//Not Complete Needs work

using namespace std;

class SymbolType : public Type {
	string _value;
	string _type = "Symbol";
public:
	explicit SymbolType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};