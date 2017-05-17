#include "LexicalEnvironmentOperation.h"
#include "Reference.h"


Reference* GetIdentifierReference(LexicalEnvironment* lex, std::string name) {
	if (lex==nullptr)
	{
		Reference* ref=new Reference(new UndefinedValue(), name);
		return ref;
	} else
	{
		EnvironmentRecord* envRec = lex->envRec;
		bool exists=envRec->HasBinding(name);
		if (exists)
		{
			Reference* ref = new Reference(envRec, name);
			return ref;
		} else
		{
			LexicalEnvironment *outer = lex->outer;
			return GetIdentifierReference(outer, name);
		}
	}
}

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment *lexicalEnv) {
	EnvironmentRecord* envRec = new DeclarativeEnvironmentRecord();
	LexicalEnvironment* env = new LexicalEnvironment(envRec);
	
	env->outer = lexicalEnv;
	return env;
}

