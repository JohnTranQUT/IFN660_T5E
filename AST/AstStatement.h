#pragma once
#include <vector>
#include "AST/AstNode.h"
#include "AST/AstExpression.h"
#include "AST/AstScript.h"

using namespace std;

class Statement : public Node {
};

class BlockStatement : public Statement {
	Statement *statement;
public:
	explicit BlockStatement(Statement *);
	void dump(int = 0) override;
};

class Block : public Statement {
	StatementList *statementlist;
public:
	explicit Block(StatementList *);
	void dump(int = 0) override;
};

class ExpressionStatement : public Statement {
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int indent) override;
};

class IfStatement : public Statement {
	Expression *cond;
	Statement *ifStatement;
	Statement *elseStatement;
public:
	explicit IfStatement(Expression *, Statement *, Statement *);
	explicit IfStatement(Expression *, Statement *);
	void dump(int indent) override;
};