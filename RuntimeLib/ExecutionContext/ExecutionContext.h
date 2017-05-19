#pragma once
#include <RuntimeLib\Type\SpecificationType\Reference\Reference.h>
#include <RuntimeLib\Type\SpecificationType\LexicalEnvironment\LexicalEnvironmentFunc.h>

Reference* ResolveBinding(StringType* name, LexicalEnvironment* env = nullptr);
