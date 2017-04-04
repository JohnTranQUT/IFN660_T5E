#include <typeinfo>
#include <AstNode.h>
#include <AstExpression.h>
#include <AstStatement.h>

using namespace std;

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	next.push_back(expression);
}

void ExpressionStatement::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}