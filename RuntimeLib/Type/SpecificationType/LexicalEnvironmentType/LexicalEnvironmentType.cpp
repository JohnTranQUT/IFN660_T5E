#include <RuntimeLib\Type\SpecificationType\LexicalEnvironmentType\LexicalEnvironmentType.h>
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <iostream>

using namespace std;

Type * GetIdenRefe(LexiEnviType * lex, string name, bool strict)
{

	auto envRec = lex->getER();
	return new ReferenceType(envRec, name, strict);
}

LexiEnviType * NewDeclEnvi(LexiEnviType * E)
{
	auto envRecord = new DeclEnviRecordType();
	auto env = new LexiEnviType(envRecord , E);
	return env;
}
