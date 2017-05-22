#pragma once
#include "RuntimeLib/Types/LanguageTypes/LanguageType.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"

BooleanType *StrictEqualityOperator(Type *, Type *, BooleanType * = new BooleanType(false));
BooleanType *AbstractEqualityOperator(Type *, Type *, BooleanType * = new BooleanType(false));