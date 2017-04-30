#pragma once
#include <string>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class BooleanType : public LanguageType {
	bool _value;
	string _type = "boolean";
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const;
	string _getType() override;
};
