#pragma once
#pragma once
#include <string>
#include <map>
#include "JSValue.h"
using namespace std;


class object {
private:
	map<string, JSValue*> property_table;
public:
	object() {
		this->property_table.clear();
	}
	void set(string propertyName, JSValue* propertyValue) {
		property_table[propertyName] = propertyValue;
	}
	JSValue* get(string propertyName) {
		map<string, JSValue*>::iterator it = property_table.find(propertyName);
		if (it != property_table.end())
			return it->second;
		return NULL;
	}
};

