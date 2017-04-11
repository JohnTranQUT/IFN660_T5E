#pragma once
#include <cstdio>
#include <string>

using namespace std;
class LanguageType {
public:
	virtual ~LanguageType() { };
	LanguageType *ToPrimitive(LanguageType *);
};

class Undefined : public LanguageType {
public:
	Undefined() { };
};

class Boolean : public LanguageType {
	bool value;
public:
	Boolean() { };
};

class Number : public LanguageType {
	double value;
public:
	Number() { };
};

class String : public LanguageType {
	string value;
public:
	String() { };
};

//class Function : public Type {
//public:
//	Function() { };
//};
//
//class Object : public Type {
//public:
//	Object() { };
//};