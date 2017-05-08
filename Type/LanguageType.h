#pragma once
#include <cstdio>
#include <string>
#include <map>
#include "Type.h"
using namespace std;

class LanguageType:public Type {
public:
	virtual ~LanguageType() { };
	//friend double ToNumber(Type);
};


class Number : public LanguageType {
private:
	double value;
	bool _isInfinitive = false; //only for negative zero and infinity, NOT for finite numbers
	bool _isNaN = false;
	bool _isPositive = true;

public:
	Number() { };
	Number(double, bool = true, bool = false);
	void set(double, bool = true);
	void set(Number);
	double get();
	bool isInfinitive() { return _isInfinitive; };
	bool isNaN() { return _isNaN; };
	bool isPositive() { return _isPositive; };
	string to_string();
	Type* to_number();
	void setInfinitive(bool, bool = true);
	Number operator+(const Number&);
};

class Undefined : public LanguageType {
public:
	Undefined() {};
	string to_string() { return "undefined"; };
	Type* to_number() { return new Number(0, true, true); };
};

class Boolean : public LanguageType {
private:
	bool value;
public:
	Boolean() { };
	Boolean(bool input) { value = input; };
	void set(bool input) { value = input; };
	bool get() { return value; };
	string to_string() { return value?"true":"false"; };
	Type* to_number() { return new Number((double)value); };
};


class String : public LanguageType {
private:
	string value;
public:
	String() { };
	String(string input) { value = input; };
	void set(string input) { value = input; };
	string get() { return value; };
	string to_string() { return value; };
};

class Function : public LanguageType {
public:
	Function() { };
};

class ObjectTypeProperty {
public:
	virtual ~ObjectTypeProperty() {};
};

class Object : public LanguageType {
private:
	map<LanguageType*, ObjectTypeProperty*> properties;
public:
	Object() { };
};