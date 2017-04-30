#include <Types/SpecificationTypes/ReferenceType/ReferenceType.h>

LanguageType *ReferenceType::GetBase() const {
	return Base;
}

LanguageType *ReferenceType::GetReference() const {
	return Referenced;
}

bool ReferenceType::IsStrictReference() const {
	return StrictReference;
}

bool ReferenceType::HasPrimitiveBase() const {
	if (dynamic_cast<BooleanType *>(Base) || dynamic_cast<StringType *>(Base) || dynamic_cast<SymbolType *>(Base) || dynamic_cast<NumberType *>(Base)) {
		return true;
	}
	return false;
}

bool ReferenceType::IsPropertyReference() const {
	if (dynamic_cast<ObjectType *>(Base) || HasPrimitiveBase()) {
		return true;
	}
	return false;
}

bool ReferenceType::IsUnresolvableReference() const {
	if (dynamic_cast<UndefinedType *>(Base)) {
		return true;
	}
	return false;
}

bool ReferenceType::IsSuperReference() const {
	return thisValue != nullptr;
}

ObjectType *ReferenceType::_getThisValue() const {
	return thisValue;
}
