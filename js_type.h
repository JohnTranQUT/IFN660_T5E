#pragma once 
#include <string>
#include <iostream>
using namespace std;


class Type {
public:
	virtual ~Type() {}
};

class GeneralType : public Type {
public:
	virtual ~GeneralType() { }
	virtual string _getType() = 0;
	virtual GeneralType* ToPrimitive(GeneralType* = nullptr) { return this; }
	virtual bool ToBoolean() = 0;
	virtual double ToNumber() = 0;
	virtual string ToString() = 0;
	//virtual GeneralType* ToObject(GeneralType* arg) = 0;
};

class Undefined : public GeneralType {
public:
	Undefined() { }
	string _getType() override { return "undefined"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { return NAN; }
	string ToString() override { return "undefined"; }
	//GeneralType* ToObject(GeneralType* arg) override { cout << "Type Error!"; }
};

class NullType : public GeneralType {
public:
	NullType() { }
	string _getType() override { return "NullType"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { return +0; }
	string ToString() override { return "null"; }
	//GeneralType* ToObject(GeneralType* arg) override { cout << "Type Error!"; }
};

class Boolean : public GeneralType {
	bool value;
public:
	Boolean(bool val) : value(val) {}
	string _getType() override { return "boolean"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { 
		if (value) { return 1; }
		else { return +0; }
		}
	string ToString() override { return (value ? "true" : "false"); }
	//GeneralType* ToObject(GeneralType* arg) override { 
	//	cout << "Boolean::ToObject";
	//	exit(0);
	//}
};

class Number : public GeneralType {
	double value;
public:
	Number(double val) : value(val) {}
	string _getType() override { return "number"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { return value; }
	string ToString() override {
		return to_string(value);
	}
	//GeneralType* ToObject(GeneralType* arg) override { cout << "Type Error!"; }
};

class String : public GeneralType {
	std::string value;
public:
	String(string val) : value(val) { }
	string _getType() override { return "string"; }
	bool ToBoolean() override { 
		if ( value == "") {	return false; }
		else { return true; }
	}
	double ToNumber() override { 
		double d;
		try {
			d = std::stod(value);
		}
		catch (const std::invalid_argument&) {
			d = NAN;
		}
		return d; 
	}
	string ToString() override { return value; }
	//GeneralType* ToObject(GeneralType* arg) override {}
};

class Object : public GeneralType {
	GeneralType *value;
public:
	Object(GeneralType *val) : value(val){ }
	GeneralType* ToPrimitive(GeneralType* = nullptr) override { return this; }
	bool ToBoolean() override { return true; }
	double ToNumber() override {
		GeneralType * primVal = ToPrimitive((GeneralType*)"Number");
		return primVal->ToNumber();
	}
	string ToString() override { 
		GeneralType * primVal = ToPrimitive((GeneralType*)"String");
		return primVal->ToString();
	}
	//GeneralType* ToObject(GeneralType* arg) override { return value; }
};

GeneralType *GetValue(GeneralType *V);
