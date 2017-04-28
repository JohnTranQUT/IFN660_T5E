#include <typeinfo>
#include "AST/AstNode.h"
#include "AST/AstExpression.h"
#include "AST/AstStatement.h"
#include "AstScript.h"

using namespace std;

BlockStatement::BlockStatement(Statement *_statement) : statement(_statement) {
	
}

void BlockStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

Block::Block(StatementList *_statementlist) : statementlist(_statementlist) {
	
}

void Block::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	
}

void ExpressionStatement::dump(int indent)
{
	
		label(indent, "ExpressionStatement\n");
		expression->dump(indent + 1);

}


IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement, Statement *_elseStatement) : cond(_expression), ifStatement(_ifStatement), elseStatement(_elseStatement) {
	vector<Node*> expComp = {cond};
	vector<Node*> ifComp = {ifStatement};
	vector<Node*> elseComp = {elseStatement};


}

IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement) : cond(_expression), ifStatement(_ifStatement), elseStatement(nullptr) {
	
}

void IfStatement::dump(int indent) {
	label(indent, "IfStatement\n");
	cond->dump(indent + 1, "cond");
	ifStatement->dump(indent + 1, "then");
	elseStatement->dump(indent + 1, "else");
}
