#include <cstdio>
#include <string>
#include <iostream>
#include <AST/Node/AstNode.h>
#include <fstream>
using namespace std;

extern ofstream outfile;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("  ");
	}
}

void Node::genCode(string message) {
	cout << message << endl;
	outfile << message << endl;
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

void Container::genCode(int *registerNum){
	//string registerVar = "r" + std::to_string((*registerNum)++);
	//auto message = "auto " + registerVar + " = new LexicalEnvonroment(new String(" + name + "))"; // Temporary environment, require fixing later.
	//Node::genCode(message);
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}
