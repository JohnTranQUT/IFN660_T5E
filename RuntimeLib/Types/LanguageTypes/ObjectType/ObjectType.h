#pragma once
#include <map>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Properties/Property.h"

using namespace std;

class ObjectType : public LanguageType {
	map<LanguageType *, Property *> Properties;
	string _type = "object";
public:
	ObjectType() { };
	static string _getValue();
	string _getType() override;
};
