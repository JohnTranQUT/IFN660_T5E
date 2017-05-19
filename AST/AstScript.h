#pragma once
#include <vector>
#include "AstNode.h"


using namespace std;

class Statement : public Node {
public:
	explicit Statement() {}
};
class Expression : public Node {
public:
	explicit Expression() {}
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
};



class Script : public Node {
	ScriptBody *scriptBody;
public:
	explicit Script(ScriptBody *scriptBody) :scriptBody(scriptBody) {}
	void dump(int indent) override {
		label(indent, "Script\n");
		scriptBody->dump(indent + 1);
	}
};
