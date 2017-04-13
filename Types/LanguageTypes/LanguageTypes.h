#pragma once
#include <string>
#include <Types/Types.h>

using namespace std;

class LanguageType;
class ObjectType;
LanguageType *ToPrimitive(LanguageType *, LanguageType * = nullptr);
bool ToBoolean(LanguageType *);
double ToNumber(LanguageType *);
int ToInteger(LanguageType *);
string ToString(LanguageType *);
ObjectType *ToObject(LanguageType *);
string _GetType(LanguageType *);

class LanguageType : public Type {
public:
	virtual ~LanguageType() { };
	virtual string _getType() = 0;
};

class UndefinedType : public LanguageType {
	string _value = "undefined";
	string _type = "undefined";
public:
	UndefinedType() { };
	string _getValue() const;
	string _getType() override;
};

class NullType : public LanguageType {
	string _value = "null";
	string _type = "object";
public:
	NullType() { };
	string _getValue() const;
	string _getType() override;
};

class BooleanType : public LanguageType {
	bool _value;
	string _type = "boolean";
public:
	explicit BooleanType(bool value) : _value(value) { };
	bool _getValue() const;
	string _getType() override;
};

class StringType : public LanguageType {
	string _value;
	string _type = "string";
public:
	explicit StringType(string value) : _value(value) { };
	string _getValue() const;
	string _getType() override;
};

class SymbolType : public LanguageType {
	string _value = "@@";
	string _type = "symbol";
public:
	SymbolType() { };
	string _getValue() const;
	string _getType() override;
};

class NumberType : public LanguageType {
	double _value;
	string _type = "number";
public:
	explicit NumberType(double value) : _value(value) { };
	double _getValue() const;
	string _getType() override;
};

class ObjectType : public LanguageType {
	string _value = "{ }";
	string _type = "object";
public:
	ObjectType() { };
	string _getValue() const;
	string _getType() override;
};