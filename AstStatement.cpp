#include <iostream>
#include <AstNode.h>
#include <AstExpression.h>
#include <AstStatement.h>

using namespace std;

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