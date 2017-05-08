#pragma once
#include <string>
using namespace std;

class Type {
public:
	virtual ~Type() { };
	virtual string to_string() { return ""; };
	virtual Type* to_number() { return nullptr; };
	friend string ToString(Type);
	friend Type* ToPrimitive(Type*, string = "default");
	friend Type* GetValue(Type* obj) { return obj; };
};