#pragma once
#include <string>
#include <Types.h>

using namespace std;

class LanguageType;
LanguageType *ToPrimitive(LanguageType *, LanguageType * = nullptr);
double ToNumber(LanguageType *);
string ToString(LanguageType *);

class LanguageType : public Type {
public:
	virtual ~LanguageType() { };
	static void *getValue() { return nullptr; };
};

class UndefinedType : public LanguageType {
public:
	UndefinedType() { };
};

class BooleanType : public LanguageType {
	bool value;
public:
	explicit BooleanType(bool _value) : value(_value) { };
	bool getValue() const;
};

class NumberType : public LanguageType {
	double value;
public:
	explicit NumberType(double _value) : value(_value) { };
	double getValue() const;
};

class StringType : public LanguageType {
	string value;
public:
	explicit StringType(string _value) : value(_value) { };
	string getValue() const;
};

class FunctionType : public Type {
public:
	FunctionType() { };
};

class ObjectType : public Type {
public:
	ObjectType() { };
};

class SymbolType : public Type {
public:
	SymbolType() { };
};