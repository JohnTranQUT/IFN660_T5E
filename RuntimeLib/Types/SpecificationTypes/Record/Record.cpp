#include <RuntimeLib/Types/SpecificationTypes/Record/Record.h>
#include <RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h>

bool RECORD_VALUE_COMP::operator()(StringType *lhs, StringType *rhs) const {
	return lhs->_getValue() < rhs->_getValue();
}

void Record::_insertValue(StringType *keyValue, Type *dataValue) {
	value.insert(pair<StringType *, Type *>(keyValue, dataValue));
}

map<StringType *, Type *, RECORD_VALUE_COMP> Record::_getValue() const {
	return value;
}

Type *Record::_findValue(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		return it->second;
	}
	return new UndefinedType();
}

BooleanType *Record::_hasValue(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *Record::_hasInitialized(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		if (it->second != nullptr) {
			return new BooleanType(true);
		}
	}
	return new BooleanType(false);
}

void Record::_setValue(StringType *keyValue, Type *dataValue) {
	value[keyValue] = dataValue;
}

BooleanType *Record::_deleteValue(StringType *keyValue) {
	if (_hasValue(keyValue)) {
		value.erase(keyValue);
		return new BooleanType(true);
	}
	return new BooleanType(false);
}
