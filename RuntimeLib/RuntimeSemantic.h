#pragma once
#include "JSValue/JSValue.h"
#include "SpecificationType/Reference.h"
#include "SpecificationType/LexicalEnvironment.h"
#include "SpecificationType/Record/DeclarativeEnvironmentRecord.h"

JSValue* assignment(Type* lref, Type* rval);

//8.1.2.1 Implementation
Reference* GetIdentifierReference(LexicalEnvironment* lex, std::string name)
{
	if (lex == nullptr)
	{
		Reference* ref = new Reference(new UndefinedValue(), name);
		return ref;
	}
	else
	{
		EnvironmentRecord* envRec = lex->envRec;
		bool exists = envRec->HasBinding(name);
		if (exists)
		{
			Reference* ref = new Reference(envRec, name);
			return ref;
		}
		else
		{
			//LexicalEnvironment *outer = lex->outer;
			//return GetIdentifierReference(outer, name);
			//create new reference
			envRec->SetMutableBinding(name, new UndefinedValue());
			Reference *ref = new Reference(envRec, name);
			return ref;
		}
	}
}

//8.1.2.2 Implementation
LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment *lexicalEnv)
{
	EnvironmentRecord* envRec = new DeclarativeEnvironmentRecord();
	LexicalEnvironment* env = new LexicalEnvironment(envRec);

	env->outer = lexicalEnv;
	return env;
}
//Execution context
Reference* ResolveBinding(std::string name, LexicalEnvironment *env)
{
	return GetIdentifierReference(env, name);
}