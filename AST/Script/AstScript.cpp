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
	next.push_back(node);
}

void StatementListItem::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void StatementListItem::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void StatementList::genCode(bool OnlyPrimitive) {
	if (!OnlyPrimitive) {
		if (lexs.size() == 0) {
			Node::genCode("NewDeclarativeEnvironment(nullptr)", false, true);
		}
		else {
			auto lex = lexs.back();
			Node::genCode(string("NewDeclarativeEnvironment(") + lex + string(")"), false, true);
		}
		for (auto &i : nodes) {
			if (auto _i = dynamic_cast<StatementListItem *>(i)) {
				if (!_i->isStatement) {
					_i->genCode(true);
					auto lex = lexs.back();
					auto ident = refs.back();
					refs.pop_back();
					Node::genCode(lex + string("->_getEnvRec()->CreateMutableBinding(" + ident + ", new BooleanType(false))"), false);
				}
			}
		}
	}
	for (auto &i : nodes) {
		i->genCode(OnlyPrimitive);
	}
	if (!OnlyPrimitive) {
		lexs.pop_back();
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

void ScriptBody::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void Script::genCode(bool OnlyPrimitive) {
	Node::genCode("#include \"RuntimeLib.h\"", false ,false, false, true);
	Node::genCode("void main() {", false, false, false, true);
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
	Node::genCode("}", false, false, false, true);
}
