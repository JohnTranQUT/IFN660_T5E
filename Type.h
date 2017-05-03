#pragma once
#include <iostream>
#include <string>

using namespace std;

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
	bool VALUE();
private:
	bool boolvalue;
};

class Number : public Type {
public:
	Number(double val) { numbervalue = val; };
	double VALUE();
protected:
	double numbervalue;
};

class String : public Type {
public:
	String(string val) { stringvalue = val; };
	string VALUE();
protected:
	string stringvalue;
};

class Function : public Type {
public:
	Function() { };
};

class Object : public Type {
public:
	Object() { };
};