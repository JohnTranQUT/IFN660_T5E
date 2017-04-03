#include <cstdio>
#include <string>
#include <iostream>
#include <ast.h>

using namespace std;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("\t");
	}
}

Identifier::Identifier(char *_identifier) {
	identifier = _identifier;
}

void Identifier::dump(int indent) {
	auto message = "Identifier (" + string(identifier) + ")";
	Node::dump(message, indent);
}

DecimalLiteral::DecimalLiteral(double _decimalLiteral) {
	decimalLiteral = _decimalLiteral;
}

void DecimalLiteral::dump(int indent) {
	auto message = "DecimalLiteral (" + to_string(decimalLiteral) + ")";
	Node::dump(message, indent);
}

AssignmentExpression::AssignmentExpression(Identifier *_identifier, DecimalLiteral *_decimalLiteral) {
	identifier = _identifier;
	decimalLiteral = _decimalLiteral;
	next.push_back(identifier);
	next.push_back(decimalLiteral);
}

void AssignmentExpression::dump(int indent) {
	auto message = "AssignmentExpression: ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

Expression::Expression(AssignmentExpression *_assignmentExpression) {
	assignmentExpression = _assignmentExpression;
	next.push_back(assignmentExpression);
}

void Expression::dump(int indent) {
	auto message = "Expression: ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

ExpressionStatement::ExpressionStatement(Expression *_expression) {
	expression = _expression;
	next.push_back(expression);
}

void ExpressionStatement::dump(int indent) {
	auto message = "ExpressionStatement: ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

Statement::Statement(ExpressionStatement *_expressionStatement) {
	expressionStatement = _expressionStatement;
	next.push_back(expressionStatement);
}

void Statement::dump(int indent) {
	auto message = "Statement: ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

Script::Script(Statement *_statement) {
	statement = _statement;
	next.push_back(statement);
}

void Script::dump(int indent) {
	auto message = "Script: ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}
