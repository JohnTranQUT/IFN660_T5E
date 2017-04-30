#pragma once
#include <string>
#include <map>
using namespace std;

class Type {
public:
	virtual Type* ToPrimitive();
	virtual bool ToBoolean();
	virtual double ToNumber()=0;
	virtual string ToString() = 0;
	virtual ~Type();
};

class UndefinedType : public Type {
public:
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	UndefinedType();
	~UndefinedType();
};
class NullType : public Type
{
public:
	NullType();
	std::string ToString() override;
	double ToNumber() override;
	~NullType();
};

class BooleanType : public Type {
private:
	bool value;
public:
	BooleanType(bool);
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	~BooleanType();
};


class NumberType : public Type {
private:
	double value;
public:
	NumberType(double _value);
	std::string ToString() override;
	double ToNumber() override;
	~NumberType();
};

class StringType : public Type {
private:
	std::string value;
public:
	StringType(std::string _value);
	bool ToBoolean() override;
	virtual std::string ToString() override;
	double ToNumber() override;
	~StringType();
};
class ObjectType : public Type
{
private:
	std::map<std::string, std::string> map_value;
public:
	ObjectType(map<std::string, std::string> _value);
	Type* ToPrimitive() override;
	bool ToBoolean() override;
	double ToNumber() override;
	std::string ToString() override;
	~ObjectType();
};


class FunctionType : public Type
{
public:
	FunctionType();
	~FunctionType();
};




