#pragma once
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>



Type* AssignmentOperator(Type* , Type* );