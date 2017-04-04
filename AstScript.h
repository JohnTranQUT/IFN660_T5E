#pragma once
#include <vector>
#include <AstNode.h>
#include <AstStatement.h>

using namespace std;

class StatementListItem : public Node {
	vector<Node*> next;
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
	explicit StatementList(StatementList*, Node *);
	void dump(int = 0) override;
};

class ScriptBody : public Node {
	vector<Node*> next;
	StatementList *statementlist;
public:
	explicit ScriptBody(StatementList *);
	void dump(int = 0) override;
};

class ScriptBody_opt : public Node {
	vector<Node*> next;
	Node *node;
public:
	explicit ScriptBody_opt(Node *);
	void dump(int = 0) override;
};

class Script : public Node {
	vector<Node*> next;
	Node *node;
public:
	explicit Script(Node *);
	void dump(int = 0) override;
};