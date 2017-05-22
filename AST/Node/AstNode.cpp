#include "AST/Node/AstNode.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

extern ofstream output;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::emit(string code, bool saveRef, bool isLex, bool pure) {
	if (pure) {
		string str;
		for (auto i = 0; i < indent; i++) {
			str += string("\t");
		}
		output << str + code;
	} else {
		string newRef;
		if (isLex) {
			newRef = string("LE") + to_string(numLex++);
			lexs.push_back(newRef);
		}
		else {
			newRef = string("R") + to_string(numRef++);
			if (saveRef) {
				refs.push_back(newRef);
			}
		}
		string str;
		for (auto i = 0; i < indent; i++) {
			str += string("\t");
		}
		str += string("auto ") + newRef + string(" = ") + code;
		output << str.c_str();
	}
	output << "\n";
}

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("  ");
	}
}

Container::Container(vector<Node *> _next, string _name) : children(_next),
                                                           name(_name) { }

void Container::dump(int indent) {
	auto message = name + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void Container::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void Container::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}
