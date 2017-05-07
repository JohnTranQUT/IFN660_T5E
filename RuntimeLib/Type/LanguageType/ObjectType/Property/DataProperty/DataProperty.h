#pragma once
#include <RuntimeLib\Type\LanguageType\ObjectType\Property\Property.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>

using namespace std;

class DataProperty : public Property {
	LanguageType* Value;
	bool Writable;
	bool Enumerable;
	bool Configurable;
public:
	explicit DataProperty(
		LanguageType* Value = new UndefinedType(),
		bool Writable = false,
		bool Enumerable = false,
		bool Configurable = false)
		: Value(Value),
		Writable(Writable),
		Enumerable(Enumerable),
		Configurable(Configurable)
	{ };

};