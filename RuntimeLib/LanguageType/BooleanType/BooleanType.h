#pragma once
#include <RuntimeLib\LanguageType\LanguageType.h>
#include <string>

using namespace std;

class BooleanType : public LanguageType {
	bool _value;
	string _type = "Boolean";
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const;
	string _getType() override;
};