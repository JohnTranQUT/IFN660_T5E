#include <typeinfo>
#include <AST/AstNode.h>
#include <AST/AstStatement.h>
#include <AST/AstScript.h>
#include <iostream>
#include <fstream>

extern ofstream SaveFile;
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

void StatementListItem::Gecode()
{
	for (auto i : next) {
		i->Gecode();
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

void StatementList::Gecode()
{
	for (auto i : next) {
		i->Gecode();
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

void ScriptBody::Gecode()
{
	for (auto i : next) {
		i->Gecode();
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

void Script::Gecode()
{
	SaveFile << "#include <C:\\Users\\Administrator\\Desktop\\rita\\SA_ENV\\RuntimeLib\\Runtime.h>" << endl;
	SaveFile << "void main() {" << endl;
	SaveFile << "auto r0 = NewDeclEnvi(nullptr);" << endl;
	push();
	for (auto &i : next) {
		i->Gecode();
	}
	SaveFile << "}" << endl;
}
