#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>

using namespace std;

Type* Reference::GetBase() const {
	return _base;
}

LanguageType* Reference::GetReferenceName() const {
	return _reference_name;
}
BooleanType* Reference::IsStrictReference() const {
	return _strict_reference;
}
BooleanType* Reference::HasPrimitiveBase() const {
	if (dynamic_cast<BooleanType *>(_base) || dynamic_cast<StringType *>(_base) || dynamic_cast<SymbolType *>(_base) || dynamic_cast<NumberType *>(_base))
		return new BooleanType(true);
	return  new BooleanType(false);
}
BooleanType* Reference::IsPropertyReference() const {
	if (HasPrimitiveBase()->_getValue() && dynamic_cast<ObjectType *>(_base)) {
		return new BooleanType(true);
	}
	return  new BooleanType(false);
}
BooleanType* Reference::IsUnresolvableReference() const {
	if(dynamic_cast<UndefinedType *>(_base))
		return  new BooleanType(true);
	return  new BooleanType(false);
}
BooleanType* Reference::IsSuperReference() const {
	if (this == _thisValue)
		return  new BooleanType(true);
	return  new BooleanType(false);
}