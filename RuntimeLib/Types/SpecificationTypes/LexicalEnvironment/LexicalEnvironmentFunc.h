#pragma once
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

ReferenceType *GetIdentifierReference(LexicalEnvironment *, StringType *, BooleanType *);
LexicalEnvironment *NewDeclarativeEnvironment(LexicalEnvironment *);
LexicalEnvironment *NewObjectEnvironment(ObjectType *, LexicalEnvironment *);
LexicalEnvironment *NewGlobalEnvironment(ObjectType *, ObjectType *);
