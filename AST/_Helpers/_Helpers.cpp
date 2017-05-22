#include "AST/_Helpers/_Helpers.h"

string _TrimDecimal(string value) {
	while (value.find(".") != string::npos && value.substr(value.length() - 1, 1) == "0" || value.substr(value.length() - 1, 1) == ".") {
		value.pop_back();
	}
	return value;
}