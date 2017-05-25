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

void StatementListItem::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}

StatementList::StatementList(Node *_node) : node(_node) {
	next.push_back(node);
}

StatementList::StatementList(StatementList *_statementlist, Node *_node) : node(_node) {
	for (auto &i : _statementlist->next) {
		next.push_back(i);
	}
	next.push_back(node);
}

void StatementList::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void StatementList::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
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

void ScriptBody::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
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

void Script::genCode(int *registerNum){
	string registerVar = "r" + std::to_string((*registerNum)++);
	string message = "Type* " + registerVar + " = NewDeclarativeEnvironment();";
	Node::genCode(message);
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}
