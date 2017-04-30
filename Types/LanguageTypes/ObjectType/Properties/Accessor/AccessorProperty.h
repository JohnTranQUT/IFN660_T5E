#pragma once
#include <Types/LanguageTypes/LanguageTypes.h>
#include "Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include <Types/LanguageTypes/ObjectType/Properties/Properties.h>

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
