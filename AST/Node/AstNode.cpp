#include <cstdio>
#include <string>
#include <iostream>
#include <AST/Node/AstNode.h>
using namespace std;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::genCode(string code, bool saveRef, bool isLex, bool semicolon, bool pure) {
	if (pure) {
		puts("");
		cout << code << (semicolon ? ";" : "") << endl;
		puts("");
	} else {
		if (isLex) {
			auto newLex = string("LE") + to_string(numLex++);
			lexs.push_back(newLex);
			cout << "\t" << "auto " << newLex << " = " << code << (semicolon ? ";" : "") << endl;
		} else {
			auto newRef = string("R") + to_string(numRef++);
			if (saveRef) {
				refs.push_back(newRef);
			}
			cout << "\t" << "auto " << newRef << " = " << code << (semicolon ? ";" : "") << endl;
		}
	}
}

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("  ");
	}
}

Container::Container(vector<Node *> _next, string _name) : next(_next),
                                                           name(_name) { }

void Container::dump(int indent) {
	auto message = name + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void Container::genCode(bool Exec) {
	for (auto &i : next) {
		i->genCode(Exec);
	}
}
