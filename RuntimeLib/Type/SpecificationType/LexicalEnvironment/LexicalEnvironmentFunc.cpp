#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironmentFunc.h>

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E) {
	auto envRec = NewDeclarativeEnvironmentRecord();
	auto env = new LexicalEnvironment(envRec, E);
	return env;
}

LexicalEnvironment * NewGlobalEnvironment(Type * G, Type * thisValue){
	//auto objRec = NewObjectRecord();
	//auto dclRec = NewDeclarativeEnvironmentRecord();
	//auto globalRec = NewGlobalEnvironmentRecord(objRec, thisValue, dclRec);
	auto globalRec = NewDeclarativeEnvironmentRecord(); //temp until above are made
	auto env = new LexicalEnvironment(globalRec, nullptr);
	return env;
}


Reference* GetIdentifierReference(LexicalEnvironment* lex, StringType* name, BooleanType* strict) {
	if (lex == nullptr || dynamic_cast<UndefinedType*>(lex)) {
		return new Reference(new UndefinedType(), name, strict);
	}
	auto envRec = lex->getEnvRec();
	if (envRec->HasBinding(name)->_getValue()) {
		return new Reference(lex->getEnvRec(), name, strict);
	}
	else {
		auto outer = lex->getOuter();
		return GetIdentifierReference(outer, name, strict);
	}
}