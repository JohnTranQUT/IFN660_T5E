#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Reference/Reference.h>

using namespace std;

Type *GetValue(Type *);
Type *PutValue(Type *, Type *);
Type *GetThisValue(Reference *);
Type *InitializeReferencedBinding(Type *, Type *);
