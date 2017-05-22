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
	if (lexs.size() < 1) {
		emit(string("NewDeclarativeEnvironment(nullptr"), false, true);
	} else {
		auto lex = lexs.back();
		emit(string("NewDeclarativeEnvironment(") + lex + string(");"), false, true);
	}

	for (auto &i : children) {
		i->instantiate();
	}

	for (auto &i : children) {
		i->evaluate();
	}
	lexs.pop_back();
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
	children.push_back(expression);
	children.push_back(ifStatement);
	children.push_back(elseStatement);
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
	expression->evaluate();
	auto exprRef = refs.back();
	refs.pop_back();
	emit(string("ToBoolean(_ToLanguageType(GetValue(") + exprRef + string(")));"));
	auto exprValue = refs.back();
	refs.pop_back();
	emit(string("if (") + exprValue + string("->_getValue()) {"), false, false, true);
	indent++;
	ifStatement->evaluate();
	indent--;
	if (elseStatement == nullptr) {
		emit(string("}"), false, false, true);
	} else {
		emit(string("} else {"), false, false, true);
		indent++;
		elseStatement->evaluate();
		indent--;
		emit(string("}"), false, false, true);
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
