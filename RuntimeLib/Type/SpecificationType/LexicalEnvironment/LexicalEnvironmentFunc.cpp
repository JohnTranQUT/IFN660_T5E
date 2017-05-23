#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironmentFunc.h>

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E) {
	auto envRec = NewDeclarativeEnvironmentRecord();
	auto env = new LexicalEnvironment(envRec, E);
	return env;
}

LexicalEnvironment* NewObjectEnvironment(map<StringType*, Type*, RECORD_COMPARE> O, LexicalEnvironment* E){
	auto envRec = NewObjectEnvironmentRecord(O);
	auto env = new LexicalEnvironment(envRec, E);
	return env;
}

LexicalEnvironment * NewGlobalEnvironment(map<StringType*, Type*, RECORD_COMPARE> G, Type * thisValue){
	auto objRec = NewObjectEnvironmentRecord(G);
	auto dclRec = NewDeclarativeEnvironmentRecord();
	auto globalRec = NewGlobalEnvironmentRecord(objRec, thisValue, dclRec);
	auto env = new LexicalEnvironment(globalRec, nullptr);
	return env;
}


Reference* GetIdentifierReference(LexicalEnvironment* lex, StringType* name, BooleanType* strict) {
	/* SPECIFICATIONS VERSION*/
	//if (lex == nullptr || dynamic_cast<UndefinedType*>(lex)) {
	//	return new Reference(new UndefinedType(), name, strict);
	//}
	auto envRec = lex->getEnvRec();
	if (envRec->HasBinding(name)->_getValue()) {
		return new Reference(lex->getEnvRec(), name, strict);
	}
	else {
		auto outer = lex->getOuter();
		/* BELOW TO SUBSTITUTE FOR GLOBAL ENVIRONMENT*/
		if(outer == nullptr){
			envRec->CreateImmutableBinding(name, strict);
			envRec->InitializeBinding(name, new UndefinedType());
			return new Reference(envRec, name, strict);
		}else
			return GetIdentifierReference(outer, name, strict);
		}
}