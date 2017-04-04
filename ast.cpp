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

Container::Container(vector<Node *> _next, string _name) : next(_next), name(_name) { }

void Container::dump(int indent) {
	auto message = name + ": ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}

Identifier::Identifier(char *_identifier) : identifier(_identifier) { }

void Identifier::dump(int indent) {
	auto message = "Identifier";
	Node::dump(message, indent);
}

DecimalLiteral::DecimalLiteral(char* _decimalLiteral) : decimalLiteral(_decimalLiteral) { }

void DecimalLiteral::dump(int indent) {
	auto message = "DecimalLiteral";
	Node::dump(message, indent);
}

Literal::Literal(Expression *_decimalLiteral) : decimalLiteral(_decimalLiteral) {
	next.push_back(decimalLiteral);
}

void Literal::dump(int indent) {
	auto message = "Literal: ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}

IdentifierReference::IdentifierReference(Expression *_identifier) : identifier(_identifier) {
	next.push_back(identifier);
}

void IdentifierReference::dump(int indent) {
	auto message = "IdentifierReference: ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}

AssignmentExpression::AssignmentExpression(Expression *_identifierReference, Expression *_literal) : identifierReference(_identifierReference), literal(_literal) {
	vector<Node*> children1 = { identifierReference };
	vector<Node*> children2 = { literal };
	auto container1 = new Container(children1, "(Dummy) LeftHandSizeExpression");
	auto container2 = new Container(children2, "(Dummy) RightHandSizeExpression");
	vector<Node*> wrapper = { container1, container2 };
	auto container = new Container(wrapper, "(Dummy Container) I am Assignment!");
	next.push_back(container);
}

void AssignmentExpression::dump(int indent) {
	auto message = "AssignmentExpression: ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	next.push_back(expression);
}

void ExpressionStatement::dump(int indent) {
	auto message = "ExpressionStatement: ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}

Script::Script(Statement *_statement) : statement(_statement) {
	next.push_back(statement);
}

void Script::dump(int indent) {
	auto message = "Script: ";
	Node::dump(message, indent);
	Node::dump("{", indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
	Node::dump("}", indent);
}
