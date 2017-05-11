#include <RuntimeLib/Types/SpecificationTypes/Reference/Reference.h>

Type *Reference::GetBase() const {
	return Base;
}

LanguageType *Reference::GetReferencedName() const {
	return Referenced;
}

BooleanType *Reference::IsStrictReference() const {
	return StrictReference;
}

BooleanType *Reference::HasPrimitiveBase() const {
	if (dynamic_cast<BooleanType *>(Base) || dynamic_cast<StringType *>(Base) || dynamic_cast<SymbolType *>(Base) || dynamic_cast<NumberType *>(Base)) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *Reference::IsPropertyReference() const {
	if (dynamic_cast<ObjectType *>(Base) || HasPrimitiveBase()->_getValue()) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *Reference::IsUnresolvableReference() const {
	if (dynamic_cast<UndefinedType *>(Base)) {
		return new BooleanType(true);
	}
	return new BooleanType(false);
}

BooleanType *Reference::IsSuperReference() const {
	return new BooleanType(thisValue != nullptr);
}

ObjectType *Reference::_getThisValue() const {
	return thisValue;
}
