#include <RuntimeLib/Types/SpecificationTypes/RecordType/RecordType.h>

void RecordType::_insertValue(StringType *keyValue, Type *dataValue) {
	value.insert(pair<string, Type *>(keyValue->_getValue(), dataValue));
}

map<string, Type *> RecordType::_getValue() const {
	return value;
}

Type *RecordType::_findValue(StringType *keyValue) {
	auto it = value.find(keyValue->_getValue());
	if (it != value.end()) {
		return it->second;
	}
	return new UndefinedType();
}

BooleanType *RecordType::_hasValue(StringType *keyValue) {
	auto it = value.find(keyValue->_getValue());
	if (it != value.end()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *RecordType::_hasInitialized(StringType *keyValue) {
	auto it = value.find(keyValue->_getValue());
	if (it != value.end()) {
		if (it->second != nullptr) {
			return new BooleanType(true);
		}
	}
	return new BooleanType(false);
}

void RecordType::_setValue(StringType *keyValue, Type *dataValue) {
	value[keyValue->_getValue()] = dataValue;
}

BooleanType *RecordType::_deleteValue(StringType *keyValue) {
	if (_hasValue(keyValue)) {
		value.erase(keyValue->_getValue());
		return new BooleanType(true);
	}
	return new BooleanType(false);
}
