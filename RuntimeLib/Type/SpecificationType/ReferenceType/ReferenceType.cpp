#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>

using namespace std;

LanguageType* ReferenceType::GetBase() const {
	return _base;
}

LanguageType* ReferenceType::GetReferenceName() const {
	return _reference_name;
}
BooleanType* ReferenceType::IsStrictReference() const {
	return _strict_reference;
}
BooleanType* ReferenceType::HasPrimitiveBase() const {
	if (dynamic_cast<BooleanType *>(_base) || dynamic_cast<StringType *>(_base) || dynamic_cast<SymbolType *>(_base) || dynamic_cast<NumberType *>(_base))
		return new BooleanType(true);
	return  new BooleanType(false);
}
BooleanType* ReferenceType::IsPropertyReference() const {
	if (HasPrimitiveBase()->_getValue() && dynamic_cast<ObjectType *>(_base)) {
		return new BooleanType(true);
	}
	return  new BooleanType(false);
}
BooleanType* ReferenceType::IsUnresolvableReference() const {
	if(dynamic_cast<UndefinedType *>(_base))
		return  new BooleanType(true);
	return  new BooleanType(false);
}
BooleanType* ReferenceType::IsSuperReference() const {
	if (this == _thisValue)
		return  new BooleanType(true);
	return  new BooleanType(false);
}