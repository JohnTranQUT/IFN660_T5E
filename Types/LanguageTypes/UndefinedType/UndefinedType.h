#pragma once
#include <string>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class UndefinedType : public LanguageType {
	string _value = "undefined";
	string _type = "undefined";
public:
	UndefinedType() { };

	string _getValue() const;

	string _getType() override;
};
