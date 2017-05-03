#pragma once
#include <cstdio>
#include <string>

using namespace std;

class Type {
public:
	virtual ~Type() { };
	virtual string to_string() {return "";};
	virtual Type to_number() { return Type(); };
	friend string ToString(Type);
	friend Type ToPrimitive(Type, string = "default");
	friend Type GetValue(Type* obj) { return *obj; };
	//friend double ToNumber(Type);
};


class Number : public Type {
private:
	double value;
	bool isInfinitive = false; //only for negative zero and infinity, NOT for finite numbers
	bool isNaN = false;
	bool isPositive = true;
public:
	Number() { };
	Number(double, bool = true, bool = false);
	void set(double, bool = true);
	double get();
	string to_string();
	Type to_number();
	void setInfinitive(bool, bool = true);
	Number operator+(const Number&);
};

class Undefined : public Type {
public:
	Undefined() {};
	string to_string() { return "undefined"; };
	Type to_number() { return Number(0, true, true); };
};

class Boolean : public Type {
private:
	bool value;
public:
	Boolean() { };
	Boolean(bool input) { value = input; };
	void set(bool input) { value = input; };
	bool get() { return value; };
	string to_string() { return value?"true":"false"; };
	Type to_number() { return Number((double)value); };
};


class String : public Type {
private:
	string value;
public:
	String() { };
	String(string input) { value = input; };
	void set(string input) { value = input; };
	string get() { return value; };
	string to_string() { return value; };
};

class Function : public Type {
public:
	Function() { };
};

class Object : public Type {
public:
	Object() { };
};