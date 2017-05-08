#pragma once
#include <RuntimeLib\LanguageType\LanguageType.h>

using namespace std;

class NullType : public LanguageType {
	string _value = "null";
	string _type = "Null";
public:
	explicit NullType() { };
	string _getValue() const;
	string _getType() override;
};