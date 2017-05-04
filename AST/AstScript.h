#pragma once
#include <vector>
#include "AST/AstNode.h"


class Statement;
using namespace std;

class StatementListItem : public Node {
	Statement *statement;
public:
	explicit StatementListItem(Statement *);
	void dump(int indent) override;
};


class StatementList : public Node {
	vector<StatementListItem*> *items;
public:
	explicit StatementList(StatementListItem* item);
	void push_back(StatementListItem *item);
	void dump(int indent) override;
};

//Jason: Could I remove this class? We dont use it.
class StatementList_opt : public Node { };

class ScriptBody : public Node {
private:
	StatementList* stmtList;
public:
	explicit ScriptBody(StatementList *stmtList);
	void dump(int indent) override;
};

//Jason: Could I remove this class? We dont use it.
class ScriptBody_opt : public Node { };

class Script : public Node {
	ScriptBody *scriptBody;
public:
	explicit Script(ScriptBody *scriptBody);
	void dump(int indent) override;
};
