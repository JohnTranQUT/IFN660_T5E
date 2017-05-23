#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

using namespace std;

class UndefinedType : public LanguageType {
	string _value = "Undefined";
	string _type = "Undefined";
public:
	UndefinedType() {};
	string _getValue() const;
	string _getType() override;
};