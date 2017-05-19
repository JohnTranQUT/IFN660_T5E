#include <RuntimeLib\ExecutionContext\ExecutionContext.h>


LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* outerEnv) {
	auto envRec = new EnvironmentRecord();
	return new LexicalEnvironment(envRec, outerEnv);
}

Reference* ResolveBinding(StringType* name, LexicalEnvironment* env){
	/*
	If env was not passed or if env is undefined, then
Let env be the running execution context's LexicalEnvironment.
Assert: env is a Lexical Environment.
If the code matching the syntactic production that is being evaluated is contained in strict mode code, let strict be true, else let strict be false.
Return ? GetIdentifierReference(env, name, strict).
*/
	if (env == nullptr || dynamic_cast<UndefinedType*>(env)) {
		puts("Let env be the running execution context's LexicalEnvironment.");//Let env be the running execution context's LexicalEnvironment.
		exit(0);
	}
	else {
		//default strict to be true or false, leave as false for now
		auto strict = new BooleanType(false);
		return GetIdentifierReference(env, name, strict);
	}
}

Reference* GetIdentifierReference(LexicalEnvironment* lex, StringType* name, BooleanType* strict) {
	if (lex = nullptr) {
		return new Reference(new UndefinedType(), name, strict);
	}
	auto envRec = lex->getEnvRec();
	if (envRec->HasBinding(name)->_getValue()) {
		return new Reference(lex, name, strict);
	}
	else {
		auto outer = lex->getOuter();
		return GetIdentifierReference(outer, name, strict);
	}
}