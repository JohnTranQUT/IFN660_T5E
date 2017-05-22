#pragma once
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Properties/Property.h"

class DataProperty : public Property {
	LanguageType *Value;
	bool Writable;
	bool Enumerable;
	bool Configurable;
public:
	explicit DataProperty(
		LanguageType *_Value = new UndefinedType(),
		bool _Writable = false,
		bool _Emumerable = false,
		bool _Configurable = false
	) : Value(_Value),
	    Writable(_Writable),
	    Enumerable(_Emumerable),
	    Configurable(_Configurable) { };
};
