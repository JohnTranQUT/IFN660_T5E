#include <typeinfo>
#include "AST/AstNode.h"
#include "AST/AstStatement.h"
#include "AST/AstScript.h"

using namespace std;

StatementListItem::StatementListItem(Statement *_statement) : statement(_statement) {
	
}

void StatementListItem::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

StatementList::StatementList(Node *_node) : node(_node) {
	
}

StatementList::StatementList(StatementList *_statementlist, Node *_node) : node(_node) {
	for (auto &i : _statementlist->nodes) {
		nodes.push_back(i);
	}
	nodes.push_back(node);
}

void StatementList::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

ScriptBody::ScriptBody(StatementList *_statementlist) : statementlist(_statementlist) {
	
}

void ScriptBody::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

Script::Script(Node *_node) : node(_node) {
	
}

void Script::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}
