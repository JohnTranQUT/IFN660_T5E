#include "JSValue.h"

	JSString::JSString(string value) {
		this->value = value;
	}
	JSNumber* JSString::ToNumber() {
		//Refer to specs 9.3.1
		try { double double_s = stof(value); return new JSNumber(double_s); }
		catch (exception e) {
			//return new jsNumber(NAN);
			return NULL;
		}
	}
	JSString* JSString::ToString() {
		return this;
	}
	JSType JSString::Type() {
		return String;
	}
	JSBoolean* JSString::ToBool() {
		if (value.length() == 0) return new JSBoolean(false);
		return new JSBoolean(true);
	}


	JSBoolean::JSBoolean(bool value) {
		this->value = value;
	}

	JSNumber* JSBoolean::ToNumber() {
		if (value) return new JSNumber(1);
		else return new JSNumber(0);
	}

	JSString* JSBoolean::ToString() {
		if (value) return new JSString("true");
		return new JSString("false");
	}

	JSType JSBoolean::Type() {
		return Bool;
	}
	JSBoolean* JSBoolean::ToBool() {
		return this;
	}

	JSNumber::JSNumber(double value) {
		this->value = value;
	}
	JSType JSNumber::Type() {
		return Number;
	}
	JSNumber* JSNumber::ToNumber() {
		return this;
	}
	JSString* JSNumber::ToString() {
		string s = std::to_string(value);
		//remove trailing zeros
		s.erase(s.find_last_not_of('0') + 1, std::string::npos);
		// remove trailing point
		if (s.back() == '.')
			s.pop_back();
		return new JSString(s);
	}

	JSBoolean* JSNumber::ToBool() {
		if (this->value == 0) {
			return new JSBoolean(false);
		}
		else {
			return new JSBoolean(true);
		}
	}

