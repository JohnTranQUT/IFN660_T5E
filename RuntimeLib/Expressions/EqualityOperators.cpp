#include <RuntimeLib\Expressions\EqualityOperators.h>

BooleanType* Equality(Type* lref, Type* rref){
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	return AbstractEqualityComparison(lval, rval);
}

BooleanType* AbstractEqualityComparison(LanguageType* x, LanguageType* y) {
	if (TypeOf(x) == TypeOf(y))
		return StrictEqualityComparsion(x, y);
	if (dynamic_cast<NullType*>(x) && dynamic_cast<UndefinedType*>(y)
		|| dynamic_cast<UndefinedType*>(x) && dynamic_cast<NullType*>(y))
		return new BooleanType(false);
	if (dynamic_cast<StringType*>(x) && dynamic_cast<NumberType*>(y)
		|| dynamic_cast<NumberType*>(x) && dynamic_cast<StringType*>(y)
		|| dynamic_cast<BooleanType*>(x)
		|| dynamic_cast<BooleanType*>(y))
		return new BooleanType(ToNumber(x)->_getValue() == ToNumber(y)->_getValue());
	//Design ObjectType and steps 8 and 9 some other time
	//if (dynamic_cast<ObjectType*>(x))
	return new BooleanType(false);
}

BooleanType* StrictEqualityComparsion(LanguageType* x, LanguageType* y) {
	if (TypeOf(x) != TypeOf(y)) {
		return new BooleanType(false);
	}
	return nullptr;
}

string TypeOf(LanguageType* x) {
	if (dynamic_cast<StringType*>(x))
		return "StringType";
	if (dynamic_cast<NumberType*>(x))
		return "NumberType";
	if (dynamic_cast<UndefinedType*>(x))
		return "UndefinedType";
	if (dynamic_cast<ObjectType*>(x))
		return "ObjectType";
	if (dynamic_cast<SymbolType*>(x))
		return "SymbolType";
	if (dynamic_cast<NullType*>(x))
		return "NullType";
}