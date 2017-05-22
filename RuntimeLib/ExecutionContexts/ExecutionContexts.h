#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Reference/Reference.h"
#include "RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h"

Reference *ResolveBinding(StringType *, LexicalEnvironment * = nullptr);
