#pragma once
#include <string>
#include <map>
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>

using namespace std;

class EnviRecordType : public SpecificationType {
public:
	map<string, Type * > ER;
	bool HasBinding(string);
	Type * CreateMutableBinding(string, bool);
	Type * InitializeBinding(string, LanguageType *);
	Type * GetBindingValue(string, bool);
	Type * SetMutableBinding(string, Type *, bool);
};

class DeclEnviRecordType : public EnviRecordType {
public:
	DeclEnviRecordType() {};
};