#pragma once
#include <map>
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"
#include "RuntimeLib/Types/LanguageTypes/ObjectType/Properties/Property.h"
#include "RuntimeLib/Types/LanguageTypes/StringType/StringType.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecord.h"

using namespace std;

struct OBJECT_VALUE_COMP {
	bool operator()(StringType *, StringType *) const;
};

class ObjectType : public LanguageType {
	map<StringType *, Type *, OBJECT_VALUE_COMP> Properties;
	string _type = "object";
public:
	ObjectType() { };
	static string _getValue();
	string _getType() override;
	Type *Get(StringType *);
	CompletionRecord *Set(StringType *, Type *);
	BooleanType *Delete(StringType *);
	BooleanType *_hasProperty(StringType *);
};
