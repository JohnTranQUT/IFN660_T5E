#include "AST/Statement/AstStatement.h"
#include <typeinfo>
#include "AST/Node/AstNode.h"
#include "AST/Expression/AstExpression.h"
#include "AST/Script/AstScript.h"
using namespace std;

BlockStatement::BlockStatement(Statement *_statement) : statement(_statement) {
	children.push_back(statement);
}

void BlockStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void BlockStatement::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void BlockStatement::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

Block::Block(StatementList *_statementlist) : statementlist(_statementlist) {
	children.push_back(statementlist);
}

void Block::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void Block::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void Block::instantiate() { }

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	children.push_back(expression);
}

void ExpressionStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ExpressionStatement::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void ExpressionStatement::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement, Statement *_elseStatement) : expression(_expression),
                                                                                                        ifStatement(_ifStatement),
                                                                                                        elseStatement(_elseStatement) {
	vector<Node*> expComp = { expression };
	vector<Node*> ifComp = { ifStatement };
	vector<Node*> elseComp = { elseStatement };
	auto expCont = new Container(expComp, "(CONDITIONS)");
	auto ifCont = new Container(ifComp, "(IF)");
	auto elseCont = new Container(elseComp, "(ELSE)");
	children.push_back(expCont);
	children.push_back(ifCont);
	children.push_back(elseCont);
}

IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement) : expression(_expression),
                                                                             ifStatement(_ifStatement),
                                                                             elseStatement(nullptr) {
	children.push_back(expression);
	children.push_back(ifStatement);
}

void IfStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void IfStatement::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void IfStatement::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

ConsoleLogStatement::ConsoleLogStatement(Expression *_expression) : expression(_expression) {
	children.push_back(expression);
}

void ConsoleLogStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ConsoleLogStatement::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	auto ref = refs.back();
	refs.pop_back();
	emit(string("_log(") + ref + string(");"), false);
}

void ConsoleLogStatement::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}
