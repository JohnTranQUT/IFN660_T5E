#pragma once
#include "SpecificationType.h"
#include "Type.h"
using namespace std;

bool HasPrimitiveBase(Reference* r)
{
	Type* temp = r->base;
	return (dynamic_cast<Boolean*>(temp) || dynamic_cast<String*>(temp) || \
		dynamic_cast<Symbol*>(temp) || dynamic_cast<Number*>(temp));
}

bool IsPropertyReference(Reference* r)
{
	return (dynamic_cast<Object*>(r->base) || HasPrimitiveBase(r));
}

bool IsUnresolvableReference(Reference* r)
{
	return !(dynamic_cast<Undefined*>(r->base));
}
Type * GetIdentifierReference(LexicalEnvironment *lex, string name, bool strict)
{
	////If lex is the value null, then
	if (!lex)
	{ //		Return a value of type Reference whose base value is undefined, whose referenced name is name, and whose strict reference flag is strict.
	}
	//	Let envRec be lex's EnvironmentRecord.
	auto* envRec = lex->GetEnvironment();
	//	Let exists be ? envRec.HasBinding(name).
	if (envRec->HasBinding(name))
	{
		//	If exists is true, then
		//	Return a value of type Reference whose base value is envRec, whose referenced name is name, and whose strict reference flag is strict.
		return envRec->GetBindingValue(name, strict);
	
	}
	//	Else,
	//		Let outer be the value of lex's outer environment reference.
	//		Return ? GetIdentifierReference(outer, name, strict).
	return GetIdentifierReference(lex->outer, name, strict);
}
Type* ResolveBinding(string name, LexicalEnvironment *env)
{
	////If env was not passed or if env is undefined, then
	//	Let env be the running execution context's LexicalEnvironment.
	//	Assert: env is a Lexical Environment.
	//	If the code matching the syntactic production that is being evaluated is contained in strict mode code, let strict be true, else let strict be false.
	//	Return ? GetIdentifierReference(env, name, strict).
	return GetIdentifierReference(env, name, false);
}

//delete not implemeted
CompletionRecord * DeclarativeEnvironmentRecord::CreateMutableBinding(string key, bool deletable)
{
	// Let envRec be the declarative Environment Record for which the method was invoked.
	//	Assert: envRec does not already have a binding for N.
	if (!HasRecord(key))
		put(key, new Reference());
	//	Create a mutable binding in envRec for N and record that it is uninitialized.If D is true, record that the newly created binding may be deleted by a subsequent DeleteBinding call.
	//	Return NormalCompletion(empty).
	CompletionRecord* result = new CompletionRecord();
	result->NormalCompletion();
	return result;
}
