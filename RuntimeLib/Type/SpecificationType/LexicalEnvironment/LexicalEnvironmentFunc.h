#pragma once
#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironment.h>
#include <RuntimeLib\Type\SpecificationType\Record\EnvironmentRecord\EnvironmentRecordFunc.h>
#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E = nullptr);
LexicalEnvironment* NewGlobalEnvironment(Type* G, Type* thisValue);
Reference* GetIdentifierReference(LexicalEnvironment* lex, StringType* name, BooleanType* strict);