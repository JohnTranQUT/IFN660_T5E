#pragma once
#include <cstdio>
#include <string>

using namespace std;

class Type {
public:
	virtual ~Type() { };
	virtual string to_string() {return "";};
	friend string ToString(Type);
	friend Type ToPrimitive(Type, string);
};

class Undefined : public Type {
public:
	Undefined() {};
	string to_string() { return "undefined"; };
};

class Boolean : public Type {
private:
	bool value;
public:
	Boolean() { };
	void set(bool input) { value = input; };
	bool get() { return value; };
};

class Number : public Type {
private:
	double value;
public:
	Number() { };
	void set(double input) { value = input; };
	double get() { return value; };
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