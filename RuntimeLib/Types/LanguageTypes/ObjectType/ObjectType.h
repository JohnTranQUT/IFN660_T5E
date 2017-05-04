#pragma once
#include <map>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypes.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/Properties/Properties.h>

using namespace std;

class ObjectType : public LanguageType {
	map<LanguageType *, Property *> Properties;
	string _type = "object";
public:
	ObjectType() { };
	static string _getValue();
	string _getType() override;
};
