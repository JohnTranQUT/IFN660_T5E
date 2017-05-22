#pragma once
#include <string>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"

using namespace std;

class SymbolType : public LanguageType {
	string _value = "@@";
	string _type = "symbol";
public:
	SymbolType() { };
	string _getValue() const;
	string _getType() override;
};
