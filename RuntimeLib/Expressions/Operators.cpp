#include "RuntimeLib\Expressions\Operators.h"
#include <string>
#include <iostream>

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
	return new NumberType(AdditiveOperatorsToNumbers(lnum, rnum));
}

Type* subtractiveOperator(Type* lref, Type* rref) {
	auto lval = GetValue(lref);
	auto rval = GetValue(rref);
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	return new NumberType(AdditiveOperatorsToNumbers(lnum, -rnum));
}

double AdditiveOperatorsToNumbers(double lnum, double rnum) {
	double result;
	//If either operand is NaN, the result is NaN.
	//The sum of two infinities of opposite sign is NaN.
	if (lnum == NAN || rnum == NAN
		|| (lnum == INFINITY && rnum == -INFINITY)
		|| (lnum == -INFINITY && rnum == INFINITY))
	{
		result = NAN;
	}

	//The sum of two infinities of the same sign is the infinity of that sign.
	//The sum of an infinity and a finite value is equal to the infinite operand.
	else if (lnum == INFINITY || lnum == -INFINITY)
	{
		result = lnum;
	}
	else if (rnum == INFINITY || rnum == -INFINITY)
	{
		result = rnum;
	}
	//The sum of two negative zeroes is −0.The sum of two positive zeroes, or of two zeroes of opposite sign, is + 0.
	//The sum of a zero and a nonzero finite value is equal to the nonzero operand.
	//The sum of two nonzero finite values of the same magnitude and opposite sign is + 0.
	//In the remaining cases, where neither an infinity, nor a zero, nor NaN is involved, 
	//	and the operands have the same sign or have different magnitudes, 
	//	the sum is computed and rounded to the nearest representable value using IEEE 754 round - to - nearest mode.If the magnitude is too large to represent, 
	//	the operation overflows and the result is then an infinity of appropriate sign.
	//	The ECMAScript language requires support of gradual underflow as defined by IEEE 754.
	else {
		result = lnum + rnum;
	}
	return result;
}

Type *assignment(Type *lref, Type *rref) {
	//AssignmentExpression:LeftHandSideExpression = AssignmentExpression
	//	If LeftHandSideExpression is neither an ObjectLiteral nor an ArrayLiteral, then
	//	Let lref be the result of evaluating LeftHandSideExpression.
	//	ReturnIfAbrupt(lref).

	//	Let rref be the result of evaluating AssignmentExpression.
	//	Let rval be ? GetValue(rref).
	//	If IsAnonymousFunctionDefinition(AssignmentExpression) and IsIdentifierRef of LeftHandSideExpression are both true, then
	//	Let hasNameProperty be ? HasOwnProperty(rval, "name").
	Type *rval = GetValue(rref);
	//	If hasNameProperty is false, perform SetFunctionName(rval, GetReferencedName(lref)).
	//	Perform ? PutValue(lref, rval).
	//	Return rval.
	PutValue(lref, rval);
	//	Let assignmentPattern be the parse of the source text corresponding to LeftHandSideExpression using AssignmentPattern[? Yield] as the goal symbol.
	//	Let rref be the result of evaluating AssignmentExpression.
	//	Let rval be ? GetValue(rref).

	//	Let status be the result of performing DestructuringAssignmentEvaluation of assignmentPattern using rval as the argument.
	//	ReturnIfAbrupt(status).
	//	Return rval.
	return rval;
}

//==================================ReferenceType functions==========================
Type* GetValue(Type* V) {

	//ReturnIfAbrupt(V).
	ReturnIfAbrupt(V);
	//	If Type(V) is not Reference, return V.
	if (V->_getType() != "Reference") {//not reference
		return V;
	}
	//	Let base be GetBase(V).
	//	If IsUnresolvableReference(V) is true, throw a ReferenceError exception.
	//	If IsPropertyReference(V) is true, then
	//	If HasPrimitiveBase(V) is true, then
	//	Assert : In this case, base will never be null or undefined.
	//	Let base be ToObject(base).
	//	Return ? base.[[Get]](GetReferencedName(V), GetThisValue(V)).
	//	Else base must be an Environment Record,
	//	Return ? base.GetBindingValue(GetReferencedName(V), IsStrictReference(V)) (see 8.1.1).
	//auto base = GetBase(V);
	//if UnresolvableReference(V)
	Reference* V_tmp = static_cast<Reference*>(V);
	//let base be GetBase(v)
	//base must be an Environment Record
	EnvironmentRecord *base = static_cast<EnvironmentRecord*>(V_tmp->GetBase());
	string refName = V_tmp->GetReferenceName();
	Type* value = base->GetBindingValue(refName);
	return value;

}
void ReturnIfAbrupt(Type* V) {
	//expand later
}

void PutValue(Type* V, Type* W) { //6.2.3.2
	//ReturnIfAbrupt(V).
	ReturnIfAbrupt(V);
	//ReturnIfAbrupt(W).
	ReturnIfAbrupt(W);
	//If Type(V) is not Reference, throw a ReferenceError exception.
	if (V->_getType() != "Reference") {//not reference
		cout << "Exception: ReferenceError1";
	}
	auto V_tmp = dynamic_cast<Reference *> (V);
	Type *base = V_tmp->GetBase();
	//Let base be GetBase(V).
	//If IsUnresolvableReference(V) is true, then
	if (V_tmp->isUnresolvableReference()) {
		//If IsStrictReference(V) is true, then
		if (V_tmp->isStrictReference()) {
			//Throw a ReferenceError exception.
			cout << "Exception: ReferenceError2";
			exit(0);
		}
		//Let globalObj be GetGlobalObject().
		//Return ? Set(globalObj, GetReferencedName(V), W, false).
	}

	//Else if IsPropertyReference(V) is true, then
	//If HasPrimitiveBase(V) is true, then
	//Assert : In this case, base will never be null or undefined.
	//	Set base to ToObject(base).
	//	Let succeeded be ? base.[[Set]](GetReferencedName(V), W, GetThisValue(V)).
	//	If succeeded is false and IsStrictReference(V) is true, throw a TypeError exception.
	//	Return.
	//	Else base must be an Environment Record,
	//	Return ? base.SetMutableBinding(GetReferencedName(V), W, IsStrictReference(V)) (see 8.1.1).
	EnvironmentRecord *envr = dynamic_cast<EnvironmentRecord*>(base);
	string name = V_tmp->GetReferenceName();
	envr->SetMutableBinding(name, W);
}


//=================Language Type Functions===================================

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


/**/


//NewDeclarativeEnvironment(E)# 8.1.2.2
//
//When the abstract operation NewDeclarativeEnvironment is called with a Lexical Environment as argument E the following steps are performed :
//
//Let env be a new Lexical Environment.
//Let envRec be a new declarative Environment Record containing no bindings.
//Set env's EnvironmentRecord to envRec.
//Set the outer lexical environment reference of env to E.
//Return env.

LexicalEnvironment * NewDeclarativeEnvironment(LexicalEnvironment* E)
{

	DeclarativeEnvironmentRecord * envRec = new DeclarativeEnvironmentRecord();
	LexicalEnvironment * env = new LexicalEnvironment(envRec);

	env->outer = E;
	return env;
}

//8.3.2 ResolveBinding(name[, env])#
//
//The ResolveBinding abstract operation is used to determine the binding of name passed as a String value.
//The optional argument env can be used to explicitly provide the Lexical Environment that is to be searched for the binding.
//During execution of ECMAScript code, ResolveBinding is performed using the following algorithm :
//
//If env was not passed or if env is undefined, then
//Let env be the running execution context's LexicalEnvironment.
//Assert : env is a Lexical Environment.
//	If the code matching the syntactic production that is being evaluated is contained in strict mode code, let strict be true, else let strict be false.
//	Return ? GetIdentifierReference(env, name, strict).

Reference * ResolveBinding(string name, LexicalEnvironment * env)
{
	return GetIdentifierReference(env, name);
}

//8.1.2.1 GetIdentifierReference(lex, name, strict)#
//
//The abstract operation GetIdentifierReference is called with a Lexical Environment lex, a String name, and a Boolean flag strict.The value of lex may be null.When called, the following steps are performed :
//
//If lex is the value null, then
//Return a value of type Reference whose base value is undefined, whose referenced name is name, and whose strict reference flag is strict.
//Let envRec be lex's EnvironmentRecord.
//Let exists be ? envRec.HasBinding(name).
//If exists is true, then
//Return a value of type Reference whose base value is envRec, whose referenced name is name, and whose strict reference flag is strict.
//Else,
//Let outer be the value of lex's outer environment reference.
//Return ? GetIdentifierReference(outer, name, strict).

Reference * GetIdentifierReference(LexicalEnvironment *lex, string name) {
	
	if (lex == nullptr)
	{
		Reference * retref = new Reference(new UndefinedType(), name);
		return retref;
	}
	EnvironmentRecord* envRec = lex->environmentRecord;
	bool exits = envRec->HasBinding(name);
	if (exits)
	{
		return new Reference(envRec, name);
	}
	else {
		//LexicalEnvironment *outer = lex->outer;
		//return GetIdentifierReference(outer, name);
		return new Reference(envRec, name);
	}
}