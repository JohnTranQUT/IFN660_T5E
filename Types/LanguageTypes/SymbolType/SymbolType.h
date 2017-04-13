#pragma once
#include <string>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class SymbolType : public LanguageType {
	string _value = "@@";
	string _type = "symbol";
public:
	SymbolType() { };
	string _getValue() const;
	string _getType() override;
};
