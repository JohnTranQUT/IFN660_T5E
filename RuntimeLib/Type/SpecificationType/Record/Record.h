#pragma once
#include <RuntimeLib\Type\SpecificationType\SpecificationType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <map>

struct RECORD_COMPARE {
	bool operator()(StringType * a, StringType * b) const;
};

class Record :public SpecificationType {
	map<StringType*, Type*, RECORD_COMPARE> _value;
public:
	virtual ~Record() {};
	map<StringType*, Type*, RECORD_COMPARE> _getValue() const;
	Type* _getValue2(StringType* key) const;
	void _setValue(StringType* key, Type* data);
	BooleanType* _hasValue(StringType* key);
};