#include <Types/SpecificationTypes/RecordType/RecordType.h>

void RecordType::_insertValue(StringType *keyValue, LanguageType *dataValue) {
	value.insert(pair<StringType *, LanguageType *>(keyValue, dataValue));
}

map<StringType *, LanguageType *> RecordType::_getValue() const {
	return value;
}

LanguageType *RecordType::_findValue(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		return it->second;
	}
	return new UndefinedType();
}
