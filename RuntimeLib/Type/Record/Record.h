#pragma once
#include <RuntimeLib\Type\Type.h>

class Record: public SpecificationType {
protected:
	map<string, Type*> symbol_table;
public:
	Record(){}
	~Record() {}
};

class EnvironmentRecord : public Record {
public:
	EnvironmentRecord(){}
	 ~EnvironmentRecord() {}
	virtual bool HasBinding(string n) = 0;
	virtual Type* GetBindingValue(string n) = 0;
	virtual void SetMutableBinding(string n, Type* v) = 0;
	virtual void InitializeBinding(string n, Type *v) = 0;
	virtual void CreateMutableBinding(string N, bool D) = 0;
};

class DeclarativeEnvironmentRecord :public EnvironmentRecord
{
public:
	DeclarativeEnvironmentRecord();
	bool HasBinding(string n) override;
	Type* GetBindingValue(string n) override;
	void InitializeBinding(string n, Type *v) override;
	void SetMutableBinding(string n, Type* v) override;
	void CreateMutableBinding(string N, bool D) override;
	~DeclarativeEnvironmentRecord() {}
};

class LexicalEnvironment
{
public:
	EnvironmentRecord *environmentRecord;
	LexicalEnvironment *outer;

	explicit LexicalEnvironment(EnvironmentRecord* _environmentRecord) :environmentRecord(_environmentRecord)
	{
		outer = nullptr;
	}
	~LexicalEnvironment() {}
};



