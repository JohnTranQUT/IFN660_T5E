#pragma once
#include "Type.h"
#include "LanguageType.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class SpecificationType :public Type {
};

class List : public SpecificationType {
private:
	vector<Type*> value;
public:
	void put(Type* input) {
		value.push_back(input);
	};
	Type* get(int index) {
		return value[index];
	};
};

class Record : public SpecificationType {
private:
	map<string, Type*> value;
public:
	void put(string nameField, Type* input) {
		value[nameField] = input;
	};
	Type* get(string key) {
		return value[key];
	}
	bool HasRecord(string key) {
		return (bool)value.count(key);
	}
};

class  CompletionRecord: public Record {
protected:
	Record* value = new Record();
public:
	CompletionRecord() {
		value->put("Type", nullptr);
		value->put("Value", nullptr);
		value->put("Target", nullptr);
	};

	void NormalCompletion(Type* arg = nullptr)
	{
		Type* temp = dynamic_cast<Type*>(new String("normal"));
		value->put("Type", temp);
		value->put("Value", arg);
		value->put("Target", nullptr);
	}
};

class Reference : public SpecificationType {
private:
	Type* base = new Undefined();
	string referencedName;
	bool isStrict;
public:
	Reference() {};
	Type* SetBase(Type* input) {
		base = input;
		return input;
	}
	friend Type* GetBase(Reference* r) { return r->base;};
	friend string GetReferenceName(Reference* r) { return r->referencedName;};
	friend bool IsStrictReference(Reference* r) { return r->isStrict;};
	friend bool HasPrimitiveBase(Reference*);
	friend bool IsPropertyReference(Reference*);
	friend bool IsUnresolvableReference(Reference*);
	friend bool IsSuperReference(Reference*) {};
};

class PropertyDescriptor : public SpecificationType {
public:

};

class EnvironmentRecord : public Record {
public:
	bool HasBinding(string name) { return HasRecord(name); };
	virtual CompletionRecord* CreateMutableBinding(string, bool) { return nullptr; };
	virtual void CreateImmutableBinding(string, bool) {};
	virtual void InitializeBinding(string, Type*) {};
	virtual void SetMutableBinding(string, Type*, bool) {};
	virtual Type* GetBindingValue(string, bool) { return nullptr; };
	virtual bool DeleteBinding(string) { return false; };
	virtual bool HasThisBinding() { return false; };
	virtual bool HasSuperBinding() { return false; };
	virtual Type* WithBaseObject() { return nullptr; };
};

class DeclarativeEnvironmentRecord : public EnvironmentRecord {
public:
	DeclarativeEnvironmentRecord() {};
	CompletionRecord* CreateMutableBinding(string, bool);	

};


class LexicalEnvironment : public SpecificationType {
private:
	EnvironmentRecord* value;
	LexicalEnvironment* outer;
public:
	LexicalEnvironment() {};
	void SetEnvironment(EnvironmentRecord* input) { value = input; };
	EnvironmentRecord* GetEnvironment() { return value; }; 
	friend Type* GetIdentifierReference(LexicalEnvironment*, string, bool);
	friend Type* ResolveBinding(string, LexicalEnvironment*);
};

class DataBlock : Type {
public:

};


