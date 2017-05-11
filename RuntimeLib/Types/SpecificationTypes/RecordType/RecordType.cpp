#include <RuntimeLib/Types/SpecificationTypes/RecordType/RecordType.h>

bool RECORD_VALUE_COMP::operator()(StringType *lhs, StringType *rhs) const {
	return lhs->_getValue() < rhs->_getValue();
}

void RecordType::_insertValue(StringType *keyValue, Type *dataValue) {
	value.insert(pair<StringType *, Type *>(keyValue, dataValue));
}

map<StringType *, Type *, RECORD_VALUE_COMP> RecordType::_getValue() const {
	return value;
}

Type *RecordType::_findValue(StringType *keyValue) {
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

BooleanType *RecordType::_hasInitialized(StringType *keyValue) {
	auto it = value.find(keyValue);
	if (it != value.end()) {
		if (it->second != nullptr) {
			return new BooleanType(true);
		}
	}
	return new BooleanType(false);
}

void RecordType::_setValue(StringType *keyValue, Type *dataValue) {
	value[keyValue] = dataValue;
}

BooleanType *RecordType::_deleteValue(StringType *keyValue) {
	if (_hasValue(keyValue)) {
		value.erase(keyValue);
		return new BooleanType(true);
	}
	return new BooleanType(false);
}
