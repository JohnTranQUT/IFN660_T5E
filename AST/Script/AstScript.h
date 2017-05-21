#pragma once
#include <vector>
#include <AST/Node/AstNode.h>

class Statement;
using namespace std;

class StatementListItem : public Node {
	vector<Node*> children;
	Node *node;
public:
	explicit StatementListItem(Node *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
	bool isStatement;
};

class StatementList : public Node {
	Node *node;
public:
	vector<Node*> nodes;
	explicit StatementList(Node *);
	explicit StatementList(StatementList *, Node *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class StatementList_opt : public Node { };

class ScriptBody : public Node {
	vector<Node*> children;
	StatementList *statementlist;
public:
	explicit ScriptBody(StatementList *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ScriptBody_opt : public Node { };

class Script : public Node {
	vector<Node*> children;
	Node *node;
public:
	explicit Script(Node *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};
