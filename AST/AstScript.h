#pragma once
#include <AST/AstNode.h>
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
	Statement* statement;
public:
	explicit StatementListItem(Statement *statement) :statement(statement) {
	}
	void dump(int indent) override;
	void GenCode(FILE* file);
	~StatementListItem() {}
};


class StatementList : public Node {
	vector<StatementListItem*> *items;
public:
	explicit StatementList(StatementListItem* item);
	void push_back(StatementListItem *item);
	void dump(int indent) override;
	void GenCode(FILE* file);
	~StatementList() {}
};

class ScriptBody : public Node {
private:
	StatementList* stmtList;
public:
	explicit ScriptBody(StatementList *stmtList) : stmtList(stmtList) {}
	void dump(int indent) override;
	void GenCode(FILE* file);
	~ScriptBody() {}
};

class Script : public Node {
	ScriptBody *scriptBody;
public:
	explicit Script(ScriptBody *scriptBody) :scriptBody(scriptBody) {}
	void dump(int indent) override;
	void GenCode(FILE* file);
	~Script() {}
};
