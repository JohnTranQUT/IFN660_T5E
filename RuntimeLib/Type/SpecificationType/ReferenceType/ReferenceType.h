#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <string>

using namespace std;

class ReferenceType : public SpecificationType {
	string _type = "Reference";
	string _valuestring;
	bool  _valueboolean;
	double _valuenumber;
	string _valueNull = "null";
	string _valueUndefined;
public:
	string _getType() ;
	Type * GetValue(Type *);
};