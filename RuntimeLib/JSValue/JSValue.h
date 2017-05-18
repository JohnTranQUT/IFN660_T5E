#pragma once
#include <string>
#include <map>
#include "RuntimeLib/Type.h"
using namespace std;

class JSValue: public Type {
public:
	virtual JSValue* ToPrimitive();
	virtual bool ToBoolean();
	virtual double ToNumber()=0;
	virtual string ToString() = 0;
	virtual ~JSValue();
};

class UndefinedValue : public JSValue {
public:
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	UndefinedValue();
	~UndefinedValue();
};
class NullValue : public JSValue
{
public:
	NullValue();
	std::string ToString() override;
	double ToNumber() override;
	~NullValue();
};

class BooleanValue : public JSValue {
private:
	bool value;
public:
	BooleanValue(bool);
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	~BooleanValue();
};


class NumberValue : public JSValue {
private:
	double value;
public:
	NumberValue(double _value);
	std::string ToString() override;
	double ToNumber() override;
	~NumberValue();
};

class StringValue : public JSValue {
private:
	std::string value;
public:
	StringValue(std::string value);
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	~StringValue();
};
class ObjectValue : public JSValue
{
private:
	std::map<std::string, std::string> map_value;
public:
	ObjectValue(map<std::string, std::string> _value);
	JSValue* ToPrimitive() override;
	bool ToBoolean() override;
	double ToNumber() override;
	std::string ToString() override;
	~ObjectValue();
};




