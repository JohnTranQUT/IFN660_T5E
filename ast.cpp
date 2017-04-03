#include <cstdio>
#include <ast.h>

using namespace std;
vector<Node*> Node::history;

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("\t");
	}
}

Identifier::Identifier(char *_identifier) {
	identifier = _identifier;
	history.emplace(history.begin(), this);
}

void Identifier::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	printf("Identifier (%s)\n", identifier);
}

int Identifier::getIndent() {
	return indent;
}

void Identifier::setIndent(int _indent) {
	indent = _indent;
}

DecimalLiteral::DecimalLiteral(double _decimalLiteral) {
	decimalLiteral = _decimalLiteral;
	history.emplace(history.begin(), this);
}

void DecimalLiteral::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	printf("Decimal Literal (%f)\n", decimalLiteral);
}

int DecimalLiteral::getIndent() {
	return indent;
}

void DecimalLiteral::setIndent(int _indent) {
	indent = _indent;
}

AssignmentExpression::AssignmentExpression(Identifier* _identifier, DecimalLiteral* _decimalLiteral) {
	identifier = _identifier;
	decimalLiteral = _decimalLiteral;
	next.push_back(identifier);
	next.push_back(decimalLiteral);
	history.emplace(history.begin(), this);
}

void AssignmentExpression::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	puts("AssignmentExpression: ");
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int AssignmentExpression::getIndent() {
	return indent;
}

void AssignmentExpression::setIndent(int _indent) {
	indent = _indent;
}

Expression::Expression(AssignmentExpression *_assignmentExpression) {
	assignmentExpression = _assignmentExpression;
	next.push_back(assignmentExpression);
	history.emplace(history.begin(), this);
}

void Expression::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	puts("Expression: ");
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int Expression::getIndent() {
	return indent;
}

void Expression::setIndent(int _indent) {
	indent = _indent;
}

ExpressionStatement::ExpressionStatement(Expression *_expression) {
	expression = _expression;
	next.push_back(expression);
	history.emplace(history.begin(), this);
}

void ExpressionStatement::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	puts("ExpressionStatement: ");
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int ExpressionStatement::getIndent() {
	return indent;
}

void ExpressionStatement::setIndent(int _indent) {
	indent = _indent;
}

Statement::Statement(ExpressionStatement *_expressionStatement) {
	expressionStatement = _expressionStatement;
	next.push_back(expressionStatement);
	history.emplace(history.begin(), this);
}

void Statement::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	puts("Statement: ");
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int Statement::getIndent() {
	return indent;
}

void Statement::setIndent(int _indent) {
	indent = _indent;
}

Script::Script(Statement *_statement) {
	statement = _statement;
	next.push_back(statement);
	history.emplace(history.begin(), this);
}

void Script::dump(int currentLevel) {
	setIndent(currentLevel);
	indentation(indent);
	puts("Script: ");
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int Script::getIndent() {
	return indent;
}

void Script::setIndent(int _indent) {
	indent = _indent;
}
