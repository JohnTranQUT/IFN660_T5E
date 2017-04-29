#pragma once
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
private:
	vector<StatementListItem*> *items;
public:
	explicit StatementList(vector<StatementListItem*> *items);
	void dump(int indent) override;
};

//Jason: Can I remove this class?
//class StatementList_opt : public Node { };

class ScriptBody : public Node {
private:
	StatementList* stmtList;
public:
	explicit ScriptBody(StatementList *stmtList);
	void dump(int indent) override;
};

//Jason: Can I remove this class? It doenst make sense.
//class ScriptBody_opt : public Node { };

class Script : public Node {
	ScriptBody *scriptBody;
public:
	explicit Script(ScriptBody *scriptBody);
	void dump(int indent) override;
};
