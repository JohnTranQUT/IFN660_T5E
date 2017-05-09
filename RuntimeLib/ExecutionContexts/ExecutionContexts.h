#pragma once
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironment.h>

ReferenceType *ResolveBinding(StringType *, LexicalEnvironment * = nullptr);
