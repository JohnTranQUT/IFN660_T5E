#pragma once
#include "LexicalEnvironment.h"
#include "Record/DeclarativeEnvironmentRecord.h"
#include "Reference.h"

//8.1.2.1 Implementation
Reference* GetIdentifierReference(LexicalEnvironment* lex, std::string name);

//8.1.2.2 Implementation
LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment *lexicalEnv);
