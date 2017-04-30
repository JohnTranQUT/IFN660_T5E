#include <Objects/ObjectConstructor.h>

ObjectType *Object(LanguageType *value) {
	if (value == nullptr || dynamic_cast<NullType*>(value) || dynamic_cast<UndefinedType*>(value)) {
		return new ObjectObject(new ObjectType());
	}
	return ToObject(value);
}

ObjectType *Boolean(LanguageType *value) {
	auto b = ToBoolean(value);
	return ToObject(b);
}

ObjectType *Number(LanguageType *value) {
	auto n = ToNumber(value);
	return ToObject(n);
}

ObjectType *String(LanguageType *value) {
	if (dynamic_cast<SymbolType*>(value)) {
		// return SymbolDescriptiveString(value);
	}
	auto s = ToString(value);
	return ToObject(s);
}
