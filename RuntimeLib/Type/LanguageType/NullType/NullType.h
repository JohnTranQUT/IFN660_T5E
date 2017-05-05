#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>

using namespace std;

class NullType : public LanguageType {
	string _value = "null";
public:
	explicit NullType() { };
	string _getValue() const;
};