#pragma once
#include <RuntimeLib\Type\LanguageType\ObjectType\Property\Property.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>


using namespace std;

class AccessorProperty : public Property {
	LanguageType* Get; //ObjectType function call or UndefinedType
	LanguageType* Set; //ObjectType function call or UndefinedType
	bool Enumerable;
	bool Configurable;
public:
	explicit AccessorProperty(
		LanguageType* Get = new UndefinedType(),
		LanguageType* Set = new UndefinedType(),
		bool Enumerable = false,
		bool Configurable = false)
		: Get(Get),
		Set(Set),
		Enumerable(Configurable),
		Configurable(Configurable)
	{ };
};