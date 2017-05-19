#include <RuntimeLib\Type\SpecificationType\Record\Record.h>

bool RECORD_COMPARE::operator()(StringType* a, StringType* b) const {
	return a->_getValue() < b->_getValue();
}

map<StringType*, Type*, RECORD_COMPARE> Record::_getValue() const {
	return _value;
}

Type* Record::_getValue2(StringType* key) const{
	return _value.find(key)->second;
}

void Record::_setValue(StringType* key, Type* data) {
	_value[key] = data;
}

BooleanType* Record::_hasValue(StringType * key){
	return new BooleanType(_value.find(key) != _value.end());
}

void Record::_insertKey(StringType* key, Type* data) {
	_value.insert(pair<StringType *, Type *>(key, data));
}

BooleanType* Record::_isInitialized(StringType* key) {
	return new BooleanType(_value.find(key) != _value.end() || _value.find(key)->second != nullptr);
}