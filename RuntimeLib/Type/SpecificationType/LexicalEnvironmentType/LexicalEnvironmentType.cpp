#include <RuntimeLib\Type\SpecificationType\LexicalEnvironmentType\LexicalEnvironmentType.h>
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Expressions\ExecutionContexts.h>
#include <iostream>

using namespace std;

Type * GetIdenRefe(LexiEnviType * lex, string name, bool strict)
{

	if (lex == nullptr)
	{
		auto _ENVI = new ReferenceType(new UndefinedType(), name, strict);
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
		envRec->CreateMutableBinding(name, false);
		return new ReferenceType(envRec, name, strict);
		//auto outer = lex->getOUT();
		//auto newENVI = GetIdenRefe(outer, name, strict);
		//return newENVI;
	}
}

LexiEnviType * NewDeclEnvi(LexiEnviType * E)
{
	auto envRecord = new DeclEnviRecordType();
	auto env = new LexiEnviType(envRecord , E);
	return env;
}
