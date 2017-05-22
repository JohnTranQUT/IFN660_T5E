#pragma once
#include <vector>
#include "AST/Node/AstNode.h"
#include "AST/Expression/AstExpression.h"
#include "AST/Script/AstScript.h"
using namespace std;

class Statement : public Node {
public:
	virtual ~Statement() = default;
	void dump(int = 0) override = 0;
	void evaluate() override = 0;
	void instantiate() override = 0;
};

class BlockStatement : public Statement {
	vector<Node*> children;
	Statement *statement;
public:
	explicit BlockStatement(Statement *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class Block : public Statement {
	vector<Node*> children;
	StatementList *statementlist;
public:
	explicit Block(StatementList *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ExpressionStatement : public Statement {
	vector<Node*> children;
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class IfStatement : public Statement {
	vector<Node*> children;
	Expression *expression;
	Statement *ifStatement;
	Statement *elseStatement;
public:
	explicit IfStatement(Expression *, Statement *, Statement *);
	explicit IfStatement(Expression *, Statement *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ConsoleLogStatement : public Statement {
	vector<Node*> children;
	Expression *expression;
public:
	explicit ConsoleLogStatement(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};