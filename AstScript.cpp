#include <AstNode.h>
#include <AstStatement.h>
#include <AstScript.h>

using namespace std;

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