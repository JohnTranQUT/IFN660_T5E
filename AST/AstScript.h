#pragma once
#include <vector>
#include "AstNode.h"


using namespace std;

class Statement : public Node {
public:
	explicit Statement() {}
	virtual void GenCode(FILE* file) = 0;
	~Statement() {}
};
class Expression : public Node {
public:
	explicit Expression() {}
	virtual int GenCode(FILE* file) = 0;
	~Expression() {}
};

class StatementListItem : public Node {
	Statement *statement;
public:
	explicit StatementListItem(Statement *statement) :statement(statement) {
	}
	void dump(int indent) override {
		label(indent, "StatementListItem\n");
		statement->dump(indent + 1);
	}
	void GenCode(FILE* file) {
		statement->GenCode(file);
	}
	~StatementListItem() {}
};


class StatementList : public Node {
	vector<StatementListItem*> *items;
public:
	explicit StatementList(StatementListItem* item)
	{
		items = new vector<StatementListItem*>();
		items->push_back(item);
	}
	void push_back(StatementListItem *item)
	{
		items->push_back(item);
	}
	void dump(int indent) override {
		label(indent, "StatementList\n");
		for (std::vector<StatementListItem*>::iterator iter = items->begin(); iter != items->end(); ++iter)
			(*iter)->dump(indent + 1);
	}
	void GenCode(FILE* file) {
		for (std::vector<StatementListItem*>::iterator iter = items->begin(); iter != items->end(); ++iter)
			(*iter)->GenCode(file);
	}
	~StatementList() {}
};

class ScriptBody : public Node {
private:
	StatementList* stmtList;
public:
	explicit ScriptBody(StatementList *stmtList) : stmtList(stmtList){}
	void dump(int indent) override {
		label(indent, "ScriptBody\n");
		stmtList->dump(indent = 1);
	}
	void GenCode(FILE* file) {
		stmtList->GenCode(file);
	}
	~ScriptBody() {}
};



class Script : public Node {
	ScriptBody *scriptBody;
public:
	explicit Script(ScriptBody *scriptBody) :scriptBody(scriptBody) {}
	void dump(int indent) override {
		label(indent, "Script\n");
		scriptBody->dump(indent + 1);
	}
	void GenCode(FILE* file) {
		scriptBody->GenCode(file);
	}
	~Script() {}
};
