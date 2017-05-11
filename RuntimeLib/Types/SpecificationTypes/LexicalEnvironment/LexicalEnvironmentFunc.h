#pragma once
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>
#include <RuntimeLib/Types/SpecificationTypes/Reference/Reference.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

Reference *GetIdentifierReference(LexicalEnvironment *, StringType *, BooleanType *);
LexicalEnvironment *NewDeclarativeEnvironment(LexicalEnvironment *);
LexicalEnvironment *NewObjectEnvironment(ObjectType *, LexicalEnvironment *);
LexicalEnvironment *NewGlobalEnvironment(ObjectType *, ObjectType *);
