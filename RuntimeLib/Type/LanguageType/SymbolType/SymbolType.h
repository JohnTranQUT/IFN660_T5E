#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
//Not Complete Needs work

using namespace std;

class SymbolType : public LanguageType {
	string _value;
	string _type = "Symbol";
public:
	explicit SymbolType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};