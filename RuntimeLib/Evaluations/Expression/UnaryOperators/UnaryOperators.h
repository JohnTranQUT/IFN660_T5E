#pragma once
#include "RuntimeLib/Types/LanguageTypes/NumberType/NumberType.h"
#include "RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h"

NumberType *UnaryPLUSOperator(Type *);
NumberType *UnaryMINUSOperator(Type *);
BooleanType *LogicalNOTOperator(Type *);
