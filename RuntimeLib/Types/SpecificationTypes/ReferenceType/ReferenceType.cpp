#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>

Type *ReferenceType::GetBase() const {
	return Base;
}

LanguageType *ReferenceType::GetReferencedName() const {
	return Referenced;
}

BooleanType *ReferenceType::IsStrictReference() const {
	return StrictReference;
}

BooleanType *ReferenceType::HasPrimitiveBase() const {
	if (dynamic_cast<BooleanType *>(Base) || dynamic_cast<StringType *>(Base) || dynamic_cast<SymbolType *>(Base) || dynamic_cast<NumberType *>(Base)) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *ReferenceType::IsPropertyReference() const {
	if (dynamic_cast<ObjectType *>(Base) || HasPrimitiveBase()->_getValue()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *ReferenceType::IsUnresolvableReference() const {
	if (dynamic_cast<UndefinedType *>(Base)) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *ReferenceType::IsSuperReference() const {
	return new BooleanType(thisValue != nullptr);
}

ObjectType *ReferenceType::_getThisValue() const {
	return thisValue;
}
