#pragma once
#include <string>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"

using namespace std;

class UndefinedType : public LanguageType {
	string _value = "undefined";
	string _type = "undefined";
public:
	UndefinedType() { };
	string _getValue() const;
	string _getType() override;
};
