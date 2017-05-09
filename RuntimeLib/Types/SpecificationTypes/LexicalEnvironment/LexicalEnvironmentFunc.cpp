#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironmentFunc.h>

ReferenceType *GetIdentifierReference(LexicalEnvironment *lex, StringType *name, BooleanType *strict) {
	if (lex == nullptr) {
		return new ReferenceType(new UndefinedType(), name, strict);
	}
	auto envRec = lex->_getEnvRec();
	auto exists = new BooleanType(false);
	if (auto _envRec = dynamic_cast<DeclarativeEnvironmentRecord *>(envRec)) {
		exists = _envRec->HasBinding(name);
	} else if (auto _envRec = dynamic_cast<ObjectEnvironmentRecord *>(envRec)) {
		exists = _envRec->HasBinding(name);
	} else if (auto _envRec = dynamic_cast<GlobalEnvironmentRecord *>(envRec)) {
		exists = _envRec->HasBinding(name);
	}
	if (exists->_getValue()) {
		return new ReferenceType(envRec, name, strict);
	}
	auto outer = lex->_getOuter();
	return GetIdentifierReference(outer, name, strict);
}

LexicalEnvironment *NewDeclarativeEnvironment(LexicalEnvironment *E) {
	auto env = new LexicalEnvironment(new DeclarativeEnvironmentRecord(), E);
	return env;
}

LexicalEnvironment *NewObjectEnvironment(ObjectType *O, LexicalEnvironment *E) {
	auto env = new LexicalEnvironment(new ObjectEnvironmentRecord(O), E);
	return env;
}

LexicalEnvironment *NewGlobalEnvironment(ObjectType *G, ObjectType *thisValue) {
	auto objRec = new ObjectEnvironmentRecord(G);
	auto dclRec = new DeclarativeEnvironmentRecord();
	auto globalRec = new GlobalEnvironmentRecord(objRec, G, dclRec);
	auto env = new LexicalEnvironment(globalRec);
	return env;
}
