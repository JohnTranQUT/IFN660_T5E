#pragma once
#include <string>
#include <map>
using namespace std;

class JSValue {
public:
	virtual JSValue* ToPrimitive();
	virtual bool ToBoolean();
	virtual double ToNumber()=0;
	virtual string ToString() = 0;
	virtual ~JSValue();
};

class JSUndefined : public JSValue {
public:
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	JSUndefined();
	~JSUndefined();
};
class JSNull : public JSValue
{
public:
	JSNull();
	std::string ToString() override;
	double ToNumber() override;
	~JSNull();
};

class JSBoolean : public JSValue {
private:
	bool value;
public:
	JSBoolean(bool);
	bool ToBoolean() override;
	std::string ToString() override;
	double ToNumber() override;
	~JSBoolean();
};


class JSNumber : public JSValue {
private:
	double value;
public:
	JSNumber(double _value);
	std::string ToString() override;
	double ToNumber() override;
	~JSNumber();
};

class JSString : public JSValue {
private:
	std::string value;
public:
	JSString(std::string _value);
	bool ToBoolean() override;
	virtual std::string ToString() override;
	double ToNumber() override;
	~JSString();
};
class JSObject : public JSValue
{
private:
	std::map<std::string, std::string> map_value;
public:
	JSObject(map<std::string, std::string> _value);
	JSValue* ToPrimitive() override;
	bool ToBoolean() override;
	double ToNumber() override;
	std::string ToString() override;
	~JSObject();
};


class JSFunction : public JSValue
{
public:
	JSFunction();
	~JSFunction();
};




