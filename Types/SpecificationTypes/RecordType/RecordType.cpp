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

BooleanType *RecordType::_hasValue(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

void RecordType::_setValue(StringType *keyValue, LanguageType *dataValue) {
	value[keyValue] = dataValue;
}

BooleanType *RecordType::_deleteValue(StringType *keyValue) {
	if (_hasValue(keyValue)) {
		value.erase(keyValue);
		return new BooleanType(true);
	}
	return new BooleanType(false);
}
