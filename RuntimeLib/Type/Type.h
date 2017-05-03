#pragma once
#include <cstdio>
#include <RuntimeLib\Type\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\NullType\NullType.h>
#include <RuntimeLib\Type\NumberType\NumberType.h>
#include <RuntimeLib\Type\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\StringType\StringType.h>
#include <RuntimeLib\Type\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\UndefinedType\UndefinedType.h>

class Type {
public:
	virtual ~Type() { };
};

class Undefined : public Type {
public:
	Undefined() { };
};

class Boolean : public Type {
public:
	Boolean() { };
};

class Number : public Type {
public:
	Number() { };
};

class String : public Type {
public:
	String() { };
};

class Function : public Type {
public:
	Function() { };
};

class Object : public Type {
public:
	Object() { };
};