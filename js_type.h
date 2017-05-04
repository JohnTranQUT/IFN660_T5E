#pragma once 
#include <string>
#include <iostream>
#include <map>
using namespace std;


class Type {
public:
	virtual ~Type() {}
	virtual string _getType() = 0;
};

class SpecificationType :public  Type {
};

class Reference : public Type
{
private:
	//base is either undefined, an Object, a Boolean, a String
	//a Symbol, a Number, or an Environment Record
	Type* base;
	string name;
	bool strictReference;
public:
	Reference(Type* _base, std::string _name) : base(_base), name(_name) {
		strictReference = false;
	}
	Type* GetBase() { return base; }
	string GetReferenceName() {	return name; }
	bool isStrictReference() { return strictReference; }
	bool isUnresolvableReference() { return (base->_getType() == "undefined") ? true : false; }
	string _getType() override { return "reference"; }
	~Reference() {}
};

class GeneralType : public Type {
public:
	virtual ~GeneralType() { }
	virtual GeneralType* ToPrimitive(string PreferredType = nullptr) { return this; }
	virtual bool ToBoolean() = 0;
	virtual double ToNumber() = 0;
	virtual string ToString() = 0;

};

class Undefined : public GeneralType {
public:
	Undefined() { }
	string _getType() override { return "undefined"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { return NAN; }
	string ToString() override { return "undefined"; }
};

class NullType : public GeneralType {
public:
	NullType() { }
	string _getType() override { return "NullType"; }
	bool ToBoolean() override { return false; }
	double ToNumber() override { return +0; }
	string ToString() override { return "null"; }
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
};

class Object : public GeneralType {
	map<string, string> map_value;
public:
	Object(map<string, string> _val) : map_value(_val){ }
	GeneralType* ToPrimitive(string PreferredType= nullptr) override {
		//If PreferredType was not passed, let hint be "default".
		//Else if PreferredType is hint String, let hint be "string".
		//Else PreferredType is hint Number, let hint be "number".
		string hint;
		if (PreferredType == "string" || PreferredType == "number")
		{
			hint = PreferredType;
		}
		else { hint = "default"; }
			//Let exoticToPrim be ? GetMethod(input, @@toPrimitive).
			//	If exoticToPrim is not undefined, then
			//	Let result be ? Call(exoticToPrim, input, « hint »).
			//	If Type(result) is not Object, return result.
			//	Throw a TypeError exception.
			//	If hint is "default", let hint be "number".
			//	Return ? OrdinaryToPrimitive(input, hint).
		//temp
		return this;
	}
	bool ToBoolean() override { return true; }
	double ToNumber() override {
		GeneralType * primVal = this->ToPrimitive("number");
		return primVal->ToNumber();
	}
	string ToString() override { 
		GeneralType * primVal = this->ToPrimitive("string");
		return primVal->ToString();
	}
};

GeneralType* GetValue(Type *V);
void PutValue(Type* v, GeneralType* w);