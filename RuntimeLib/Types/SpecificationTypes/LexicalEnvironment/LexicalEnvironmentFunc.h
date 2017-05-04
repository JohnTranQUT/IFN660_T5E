#pragma once
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>

ReferenceType *GetIdentifierReference(LexicalEnvironment *, StringType *, BooleanType *);
LexicalEnvironment *NewDeclarativeEnvironment(EnvironmentRecord *);