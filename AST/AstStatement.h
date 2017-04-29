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
	void dump(int indent) override;
};

class Block : public Statement {
	StatementList *stmtList;
public:
	explicit Block(StatementList *stmtList);
	void dump(int indent) override;
};

class ExpressionStatement : public Statement {
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int indent) override;
};

class IfStatement : public Statement {
	Expression *cond;
	Statement *thenStmt;
	Statement *elseStmt;
public:
	explicit IfStatement(Expression *cond, Statement *thenStmt, Statement *elseStmt);
	explicit IfStatement(Expression *cond, Statement *thenStmt);
	void dump(int indent) override;
};