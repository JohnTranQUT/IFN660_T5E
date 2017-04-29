#include <typeinfo>
#include "AST/AstNode.h"
#include "AST/AstExpression.h"
#include "AST/AstStatement.h"
#include "AstScript.h"

using namespace std;

BlockStatement::BlockStatement(Statement *_statement) : statement(_statement) {
	
}

void BlockStatement::dump(int indent) {
	label(indent, "Block\n");
	statement->dump(indent + 1);
	
}

Block::Block(StatementList *stmtList) : stmtList(stmtList) {
	
}

void Block::dump(int indent) {
	label(indent, "Block\n");
	stmtList->dump(indent + 1);
}

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	
}

void ExpressionStatement::dump(int indent)
{
	label(indent, "ExpressionStatement\n");
	expression->dump(indent + 1);
}


IfStatement::IfStatement(Expression* cond, Statement* thenStmt, Statement* elseStmt): cond(cond),thenStmt(thenStmt),elseStmt(elseStmt)
{
}

IfStatement::IfStatement(Expression* cond, Statement* thenStmt): cond(cond), thenStmt(thenStmt)
{
}

void IfStatement::dump(int indent) {
	label(indent, "IfStatement\n");
	cond->dump(indent + 1, "cond");
	thenStmt->dump(indent + 1, "then");
	elseStmt->dump(indent + 1, "else");
}
