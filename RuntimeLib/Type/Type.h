#pragma once
#include <cstdio>
#include <string>
#include <map>

using namespace std;

class Type {
public:
	Type() {}
	virtual ~Type() {}
	virtual string _getType() {
		return "undefined";
	}
};
//Functions for Language typed Types(or values)
class UndefinedType : public Type {
	//string _value;
	string _type = "Undefined";
public:
	explicit UndefinedType() { }

};

class NullType : public Type {
	string _value = "null";
	string _type = "Null";
public:
	explicit NullType() { };
	string _getValue() const {
		return _value;
	}
	string _getType() override {
		return _type;
	}
};

class BooleanType : public Type {
	bool _value;
	string _type = "Boolean";
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const {
		return _value;
	}
	string _getType() override {
		return _type;
	}

};

class NumberType : public Type {
	double _value;
	string _type = "Number";
public:
	explicit NumberType(double value) : _value(value) { };
	double _getValue() const {
		return _value;
	}
	string _getType() override {
		return _type;
	}
};

class StringType : public Type {
	string _value;
	string _type = "String";
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const {
		return _value;
	}
	string _getType() override {
		return _type;
	}
};
//specification type- reference type

class SpecificationType : public Type {
public:
	SpecificationType(){}
	~SpecificationType() {}
};

class Reference : public SpecificationType {
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
	string GetReferenceName() { return name; }
	bool isStrictReference() { return strictReference; }
	bool isUnresolvableReference() { return (base->_getType() == "undefined") ? true : false; }
	string _getType() override { return "Reference"; }
	~Reference() {}
};