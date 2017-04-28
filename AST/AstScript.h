#pragma once
#include "AST/AstNode.h"


class Statement;
using namespace std;

class StatementListItem : public Node {
	Statement *statement;
public:
	explicit StatementListItem(Statement *);
	void dump(int = 0) override;
};

class StatementList : public Node {
	Node *node;
public:
	vector<Node*> nodes;
	explicit StatementList(Node *);
	explicit StatementList(StatementList *, Node *);
	void dump(int = 0) override;
};

class StatementList_opt : public Node { };

class ScriptBody : public Node {
	StatementList *statementlist;
public:
	explicit ScriptBody(StatementList *);
	void dump(int = 0) override;
};

class ScriptBody_opt : public Node { };

class Script : public Node {
	Node *node;
public:
	explicit Script(Node *);
	void dump(int = 0) override;
};
