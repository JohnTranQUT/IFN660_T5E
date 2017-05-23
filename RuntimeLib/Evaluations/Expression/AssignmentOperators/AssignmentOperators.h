#pragma once
#include <string>
#include "RuntimeLib/Types/Type.h"

using namespace std;

Type *SimpleAssignmentOperator(Type *, Type *);
Type *CompoundAssignmentOperator(Type *, string, Type *);