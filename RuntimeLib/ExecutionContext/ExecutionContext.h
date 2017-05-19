#pragma once
#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironment.h>
#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>

LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* outerEnv = nullptr);
Reference* ResolveBinding(StringType* name, LexicalEnvironment* env = nullptr);
Reference* GetIdentifierReference(LexicalEnvironment* lex, StringType* name, BooleanType* strict);

