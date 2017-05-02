#pragma once
#include <cstdio>
#include <iostream>

class Type {
public:
	virtual ~Type() { };
private:
	char * str;
	double num;
	bool boolean;
};

class Undefined : public Type {
public:
	Undefined() { };
	virtual Type ToPrimitive(Type);
};

class Boolean : public Type {
public:
	Boolean() { }
	friend bool ToBoolean(Type);
};

class Number : public Type {
public:
	Number() { };
};

class String : public Type {
public:
};

class Function : public Type {
public:
	Function() { };
};

class Object : public Type {
public:
	Object() { };
};