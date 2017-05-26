#pragma once
#include <vector>
#include <AST/Node/AstNode.h>
#include <AST/Statement/AstStatement.h>
class Statement;
using namespace std;

class StatementListItem : public Node {
	vector<Node*> next;
	Statement *statement;
public:
	explicit StatementListItem(Statement *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class StatementList : public Node {
	Node *node;
public:
	vector<Node*> nodes;
	explicit StatementList(Node *);
	explicit StatementList(StatementList *, Node *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class StatementList_opt : public Node { };

class ScriptBody : public Node {
	vector<Node*> next;
	StatementList *statementlist;
public:
	explicit ScriptBody(StatementList *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class ScriptBody_opt : public Node { };

class Script : public Node {
	vector<Node*> next;
	Node *node;
public:
	explicit Script(Node *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};
