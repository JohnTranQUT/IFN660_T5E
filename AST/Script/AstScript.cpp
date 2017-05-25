#include <typeinfo>
#include <AST/Node/AstNode.h>
#include <AST/Statement/AstStatement.h>
#include <AST/Script/AstScript.h>
using namespace std;

StatementListItem::StatementListItem(Statement *_statement) : statement(_statement) {
	next.push_back(statement);
}

void StatementListItem::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int StatementListItem::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int StatementList::eval(int line, FILE* output) {
	for (auto &i : nodes) {
		line = i->eval(line, output);
	}
	return line;
}

ScriptBody::ScriptBody(StatementList *_statementlist) : statementlist(_statementlist) {
	next.push_back(statementlist);
}

void ScriptBody::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int ScriptBody::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
}

Script::Script(Node *_node) : node(_node) {
	next.push_back(node);
}

void Script::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int Script::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
}
