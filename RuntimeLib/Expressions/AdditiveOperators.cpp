#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>

//Evaluation Functions

Type* additiveOperator(Type* lref, Type* rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lprim = ToPrimative(lval);
	auto rprim = ToPrimative(rval);
	if (dynamic_cast<StringType *>(lprim) || dynamic_cast<StringType *>(rprim)) {
		string lstr = (ToString(lprim))->_getValue();
		string rstr = (ToString(rprim))->_getValue();
		return new StringType(lstr + rstr);
	}
	auto lnum = ToNumber(lprim)->_getValue();
	auto rnum = ToNumber(rprim)->_getValue();
	return new NumberType(lnum + rnum);
}

Type* subtractiveOperator(Type* lref, Type* rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	return new NumberType(lnum - rnum);
}

//==================================ReferenceType functions==========================
Type* GetValue(Type* V) {
	ReturnIfAbrupt(V);
	if (V->_getType() != "Reference") {//not reference
		return V;
	}
	//auto base = GetBase(V);
	//if UnresolvableReference(V)

}

Type* ToPrimative(Type* input, Type* preferredType) {
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
	/*if (dynamic_cast<SymbolType *>(input))
		return input;
	*/
	/*if (auto _input = dynamic_cast<ObjectType *>(input))
		???
	*/
}

void ReturnIfAbrupt(Type* V) {
	//Will fill
}

//=================Type Functions===================================
StringType* ToString(Type* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return new StringType("Nan");
	if (auto _V = dynamic_cast<NullType *>(V))
		return new StringType("null");
	if (auto _V = dynamic_cast<BooleanType *>(V))
		if (_V->_getValue() == true)
			return new StringType("true");
		else
			return new StringType("false");
	if (auto _V = dynamic_cast<NumberType *>(V))
		if (isnan(_V->_getValue()))
			return  new StringType("Nan");
		else
			return new StringType(to_string(_V->_getValue()));
	if (auto _V = dynamic_cast<StringType *>(V)) 
		return _V;
	
	/*if (auto _V = dynamic_cast<SymbolType *>(V))
		std::puts("TypeError");
		exit(0);
	*/
	/*if (auto _V = dynamic_cast<ObjectType *>(V))
		return _V->_getValue();
	*/
}

NumberType* ToNumber(Type* V) {
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
	/*if (auto _V = dynamic_cast<SymbolType *>(V))
	std::puts("TypeError");
	exit(0);
	*/
	/*if (auto _V = dynamic_cast<ObjectType *>(V))
	return _V->_getValue();
	*/
}