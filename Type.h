#pragma once
#include <cstdio>

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