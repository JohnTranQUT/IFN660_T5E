#include <cstdio>
#include <string>
#include <iostream>
#include <AST/Node/AstNode.h>
#include <fstream>
using namespace std;

extern ofstream output;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::emit(string code, bool saveRef, bool isLex, bool semicolon, bool pure) {
	if (pure) {
		auto str = code + (semicolon ? ";" : "");
		output << str.c_str();
	} else {
		if (isLex) {
			auto newLex = string("LE") + to_string(numLex++);
			lexs.push_back(newLex);
			auto str = string("\t") + string("auto ") + newLex + string(" = ") + code + (semicolon ? ";" : "");
			output << str.c_str();
		} else {
			auto newRef = string("R") + to_string(numRef++);
			if (saveRef) {
				refs.push_back(newRef);
			}
			auto str = string("\t") + string("auto ") + newRef + string(" = ") + code + (semicolon ? ";" : "");
			output << str.c_str();
		}
	}
	output << "\r\n";
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
