#include <string>
#include <AstNode.h>
#include <AstExpression.h>

using namespace std;

Identifier::Identifier(char *_identifier) : identifier(_identifier) { }

void Identifier::dump(int indent) {
	auto message = "Identifier (" + string(identifier) + ")";
	Node::dump(message, indent);
}

DecimalLiteral::DecimalLiteral(double _decimalLiteral) : decimalLiteral(_decimalLiteral) { }

void DecimalLiteral::dump(int indent) {
	auto message = "DecimalLiteral (" + to_string(decimalLiteral) + ")";
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
	next.push_back(identifierReference);
	next.push_back(literal);
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