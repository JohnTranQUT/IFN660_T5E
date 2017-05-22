#pragma once
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Properties/Property.h"

class AccessorProperty : public Property {
	LanguageType *Get;
	LanguageType *Set;
	bool Enumerable;
	bool Configurable;
public:
	explicit AccessorProperty(
		LanguageType *_Get = new UndefinedType(),
		LanguageType *_Set = new UndefinedType(),
		bool _Enumerable = false,
		bool _Configurable = false
	) : Get(_Get),
	    Set(_Set),
	    Enumerable(_Enumerable),
	    Configurable(_Configurable) { };
};