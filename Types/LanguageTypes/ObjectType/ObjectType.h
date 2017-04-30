#pragma once
#include <vector>
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/LanguageTypes/ObjectType/Properties/Properties.h>

using namespace std;

class ObjectType : public LanguageType {
	vector<LanguageType *> keys;
	vector<Property *> properties;
	string _type = "object";
public:
	ObjectType() { };
	static string _getValue();
	string _getType() override;
};
