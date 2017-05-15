#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

//Evaluation Functions

LanguageType* additiveOperator(Type* lref, Type* rref) {
	auto lval = ToLanguageType(GetValue(lref));
	auto rval = ToLanguageType(GetValue(rref));
	auto lprim = ToPrimative(lval);
	auto rprim = ToPrimative(rval);
	if (dynamic_cast<StringType *>(lprim) || dynamic_cast<StringType *>(rprim)) {
		string lstr = ToString(lprim);
		string rstr = ToString(rprim);
		return new StringType(lstr + rstr);
	}
	auto lnum = ToNumber(lprim)->_getValue();
	auto rnum = ToNumber(rprim)->_getValue();
	return new NumberType(lnum + rnum);
}

LanguageType* subtractiveOperator(LanguageType* lref, LanguageType* rref) {
	auto lval = ToLanguageType(GetValue(lref));;
	auto rval = ToLanguageType(GetValue(rref));
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	return new NumberType(lnum - rnum);
}



//=================Language Type Functions===================================

LanguageType* ToPrimative(LanguageType* input, LanguageType* preferredType) {
	if (dynamic_cast<UndefinedType *>(input))
		return input;
	if (dynamic_cast<NullType *>(input))
		return input;
	if (dynamic_cast<BooleanType *>(input))
		return input;
	if (dynamic_cast<NumberType *>(input))
		return input;
	if (dynamic_cast<StringType *>(input))
		return input;
	if (dynamic_cast<SymbolType *>(input))
		return input;
//	if (auto _input = dynamic_cast<ObjectType *>(input))
		

}

string ToString(LanguageType* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return "Nan";
	if (auto _V = dynamic_cast<NullType *>(V))
		return "null";
	if (auto _V = dynamic_cast<BooleanType *>(V))
		if (_V->_getValue() == true)
			return "true";
		else
			return "false";
	if (auto _V = dynamic_cast<NumberType *>(V))
		if (isnan(_V->_getValue()))
			return  "Nan";
		else
			return to_string(_V->_getValue());
	if (auto _V = dynamic_cast<StringType *>(V)) 
		return _V->_getValue();
	
	if (auto _V = dynamic_cast<SymbolType *>(V))
	{
		std::puts("TypeError");
		exit(0);
	}

}

NumberType* ToNumber(LanguageType* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return new NumberType(NAN);
	if (auto _V = dynamic_cast<NullType *>(V))
		return new NumberType(0);
	if (auto _V = dynamic_cast<BooleanType *>(V))
		if (_V->_getValue() == true)
			return new NumberType(1);
		else
			return new NumberType(0);
	if (auto _V = dynamic_cast<NumberType *>(V))
		return _V;
	if (auto _V = dynamic_cast<StringType *>(V))
		try{
			return new NumberType(stod(_V->_getValue()));
		} catch (const invalid_argument) {
			return new NumberType(NAN);
		}
	if (auto _V = dynamic_cast<SymbolType *>(V))
	std::puts("TypeError");
	exit(0);
	
}

ObjectType * ToObject(Type * V)
{
	return nullptr;
}
