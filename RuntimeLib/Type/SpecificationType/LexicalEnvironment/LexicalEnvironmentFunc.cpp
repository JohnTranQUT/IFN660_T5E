#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironmentFunc.h>

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