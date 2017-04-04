#pragma once
#include <vector>
#include <AstNode.h>
#include <AstStatement.h>

using namespace std;

class Script : public Node {
	vector<Node*> next;
	Statement *statement;
public:
	explicit Script(Statement *);
	void dump(int = 0) override;
};