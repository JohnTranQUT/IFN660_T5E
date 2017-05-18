#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\SpecificationType\LexicalEnvironmentType\LexicalEnvironmentType.h>
#include <string>

using namespace std;

class ReferenceType : public SpecificationType {
private:
	string _type = "Reference";
	Type * base;
	string name;
	bool strict;

public:
	string _getType() ;
	ReferenceType(Type * _base, string _name, bool _strict)
	{
		base = _base;	name = _name;	strict = _strict;
	}
	bool IsUnresolvableReference(Type *);
	bool IsPropertyReference(Type *);
	bool HasPrimitiveBase(Type *);
	Type * GetBase();
	string GetReferenceName(Type *);
	bool IsStrictReference(Type *);
};

Type * GetValue(Type * );
Type * PutValue(Type *, Type *);
Type * InitializeReferencedBinding(Type *, Type *);
void ReturnIfAbrupt(Type*);