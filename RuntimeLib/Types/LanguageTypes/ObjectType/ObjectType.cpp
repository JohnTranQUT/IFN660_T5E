#include "RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h"
#include "RuntimeLib/Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h"

bool OBJECT_VALUE_COMP::operator()(StringType *lhs, StringType *rhs) const {
	return lhs->_getValue() < rhs->_getValue();
}

string ObjectType::_getValue() {
	return "[object Object]";
}

string ObjectType::_getType() {
	return _type;
}

Type *ObjectType::Get(StringType *key) {
	auto it = Properties.find(key);
	if (it != Properties.end()) {
		return it->second;
	}
	return new UndefinedType();
}

CompletionRecord *ObjectType::Set(StringType *key, Type *value) {
	Properties[key] = value;
	return NormalCompletion(nullptr);
}

BooleanType *ObjectType::Delete(StringType *key) {
	auto it = Properties.find(key);
	if (it != Properties.end()) {
		Properties.erase(it);
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *ObjectType::_hasProperty(StringType *key) {
	auto it = Properties.find(key);
	if (it != Properties.end()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}
