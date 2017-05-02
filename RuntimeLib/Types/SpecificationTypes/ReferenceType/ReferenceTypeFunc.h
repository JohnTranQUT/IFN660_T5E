#pragma once
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>

using namespace std;

Type *GetValue(Type *);
Type *PutValue(Type *, Type *);
LanguageType *GetThisValue(ReferenceType *);
