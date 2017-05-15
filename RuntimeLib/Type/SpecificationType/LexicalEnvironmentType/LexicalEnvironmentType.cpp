#include <RuntimeLib\Type\SpecificationType\LexicalEnvironmentType\LexicalEnvironmentType.h>
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <iostream>

using namespace std;

Type * GetIdentRefe(LexiEnviType * lex, string name, bool strict)
{
	if (lex == nullptr)
	{
		auto _ENVI = new ReferenceType(new UndefinedType("undefined"), name, strict);
		return _ENVI;
	}

	auto envRec = lex->getER();
	auto exsit = envRec->HasBinding(name);
	if (exsit == true)
	{
		auto _ENVI = new ReferenceType(envRec, name, strict);
		return _ENVI;
	}
	else
	{
		auto outer = lex->getOUT();
		auto newENVI = GetIdentRefe(outer, name, strict);
		return newENVI;
	}
}

LexiEnviType * NewDeclEnvi(LexiEnviType * E= nullptr)
{
	auto envRecord = new DeclEnviRecordType();
	auto env = new LexiEnviType(envRecord , E);
	return env;
}
