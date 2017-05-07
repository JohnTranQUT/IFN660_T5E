#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\Property\Property.h>
#include <map>

using namespace std;

class ObjectType : public LanguageType {
	map<LanguageType*, Property*> properties;
public:
	explicit ObjectType() { };
};