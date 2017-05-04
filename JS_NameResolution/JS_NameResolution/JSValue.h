#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;
enum JSType { Number, String, Bool, Reference };

class JSString;
class JSNumber;
class JSBoolean;


class JSValue
{

public:
	virtual JSType Type() = 0;
	virtual JSNumber* ToNumber() = 0;
	virtual JSString* ToString() = 0;
	virtual JSBoolean* ToBool() = 0;
};
class JSString : public JSValue {
public:
	string value;
public:
	__declspec(dllexport) JSString(string);
	__declspec(dllexport) JSNumber* ToNumber();
	__declspec(dllexport) JSString* ToString();
	__declspec(dllexport) JSBoolean* ToBool();
	__declspec(dllexport) JSType Type();
	
};


class JSBoolean : public JSValue {
public:
	bool value;
public:
	__declspec(dllexport) JSBoolean(bool);
	__declspec(dllexport) JSNumber* ToNumber();
	__declspec(dllexport) JSString* ToString();
	__declspec(dllexport) JSBoolean* ToBool();
	__declspec(dllexport) JSType Type();
	
};

class JSNumber : public JSValue {
public:
	double value;
public:
	__declspec(dllexport) JSNumber(double);
	__declspec(dllexport) JSNumber* ToNumber();
	__declspec(dllexport) JSString* ToString();
	__declspec(dllexport) JSBoolean* ToBool();
	__declspec(dllexport) JSType Type();
	
};
