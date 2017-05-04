#pragma once
#include <string>
#include <iostream>
#include <map>
#include "JSValue.h"
#include "JSObject.h"


using namespace std;

class JSReference : public JSValue
{
public:
	JSObject* base;
	string name;

public:
	JSReference(JSObject* base, string name)
	{
		this->base = base;
		this->name = name;
	}
	JSType Type() {
		return Reference;
	}
	JSNumber* ToNumber() {
		return NULL;
	}
	JSString* ToString() {
		return NULL;
	}
	JSBoolean* ToBool() {
		return NULL;
	}
};