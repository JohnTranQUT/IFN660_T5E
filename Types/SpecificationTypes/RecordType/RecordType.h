#pragma once
#include <map>
#include <Types/SpecificationTypes/SpecificationTypes.h>
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <Types/LanguageTypes/StringType/StringType.h>
#include <Types/LanguageTypes/BooleanType/BooleanType.h>

using namespace std;

class RecordType : public SpecificationType {
	map<StringType *, LanguageType *> value;
public:
	RecordType() { };
	void _insertValue(StringType *, LanguageType *);
	map<StringType *, LanguageType *> _getValue() const;
	LanguageType *_findValue(StringType *);
	BooleanType *_hasValue(StringType *);
	BooleanType *_hasInitialized(StringType *);
	void _setValue(StringType *, LanguageType *);
	BooleanType *_deleteValue(StringType *);
};
