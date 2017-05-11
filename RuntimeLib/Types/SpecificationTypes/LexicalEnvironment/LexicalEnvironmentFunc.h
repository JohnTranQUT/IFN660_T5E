#pragma once
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>
#include <RuntimeLib/Types/SpecificationTypes/Reference/Reference.h>

Reference *GetIdentifierReference(LexicalEnvironment *, StringType *, BooleanType *);
LexicalEnvironment *NewDeclarativeEnvironment(LexicalEnvironment *);
LexicalEnvironment *NewObjectEnvironment(ObjectType *, LexicalEnvironment *);
LexicalEnvironment *NewGlobalEnvironment(ObjectType *, ObjectType *);
