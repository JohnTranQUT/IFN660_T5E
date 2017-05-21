#include <typeinfo>
#include <AST/Node/AstNode.h>
#include <AST/Statement/AstStatement.h>
#include <AST/Script/AstScript.h>
#include <iostream>

using namespace std;

StatementListItem::StatementListItem(Node *_node) : node(_node) {
	if (dynamic_cast<Statement *>(node)) {
		isStatement = true;
	} else {
		isStatement = false;
	}
	children.push_back(node);
}

void StatementListItem::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void StatementListItem::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void StatementListItem::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

StatementList::StatementList(Node *_node) : node(_node) {
	nodes.push_back(node);
}

StatementList::StatementList(StatementList *_statementlist, Node *_node) : node(_node) {
	for (auto &i : _statementlist->nodes) {
		nodes.push_back(i);
	}
	nodes.push_back(node);
}

void StatementList::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : nodes) {
		i->dump(indent + 1);
	}
}

void StatementList::evaluate() {
	for (auto &i : nodes) {
		i->evaluate();
	}
}

void StatementList::instantiate() {
	for (auto &i : nodes) {
		if (auto _i = dynamic_cast<StatementListItem *>(i)) {
			if (!_i->isStatement) {
				_i->instantiate();
				auto lex = lexs.back();
				auto ident = refs.back();
				refs.pop_back();
				emit(lex + string("->_getEnvRec()->CreateMutableBinding(" + ident + ", new BooleanType(false))"), false);
			}
		}
	}
}

ScriptBody::ScriptBody(StatementList *_statementlist) : statementlist(_statementlist) {
	children.push_back(statementlist);
}

void ScriptBody::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ScriptBody::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void ScriptBody::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

Script::Script(Node *_node) : node(_node) {
	children.push_back(node);
}

void Script::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void Script::evaluate() {
	emit("#include \"RuntimeLib.h\"", false, false, false, true);
	emit("void main() {", false, false, false, true);

	if (lexs.size() == 0) {
		emit("NewDeclarativeEnvironment(nullptr)", false, true);
	}
	else {
		auto lex = lexs.back();
		emit(string("NewDeclarativeEnvironment(") + lex + string(")"), false, true);
	}

	for (auto &i : children) {
		i->instantiate();
	}

	for (auto &i : children) {
		i->evaluate();
	}

	lexs.pop_back();

	emit("}", false, false, false, true);
}

void Script::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}
