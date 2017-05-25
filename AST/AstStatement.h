#pragma once
#include <AST/AstNode.h>
#include <AST/AstScript.h>
using namespace std;
class BlockStatement : public Statement {
	Statement *statement;
public:
	explicit BlockStatement(Statement *statement) :statement(statement) {}
	void dump(int indent) override;
	void GenCode(FILE* file) override;
};

class Block : public Statement {
	StatementList *stmtList;
public:
	explicit Block(StatementList *stmtList) :stmtList(stmtList) {}
	void dump(int indent) override;
	void GenCode(FILE* file) override;
};

class ExpressionStatement : public Statement {
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *expression) :expression(expression) {}
	void dump(int indent) override;
	void GenCode(FILE* file) override;
};

class IfStatement : public Statement {
	Expression *cond;
	Statement *thenStmt;
	Statement *elseStmt;
public:
	explicit IfStatement(Expression *cond, Statement *thenStmt, Statement *elseStmt) :cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {}
	explicit IfStatement(Expression *cond, Statement *thenStmt) :cond(cond), thenStmt(thenStmt)
	{
		elseStmt = nullptr;
	}
	void dump(int indent) override;
	void GenCode(FILE* file) override;
};