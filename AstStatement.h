#pragma once
#include <vector>
#include <AstNode.h>
#include <AstExpression.h>

using namespace std;

class Statement : public Node {
public:
	virtual ~Statement() = default;
	void dump(int = 0) override = 0;
};

class ExpressionStatement : public Statement {
	vector<Node*> next;
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int = 0) override;
};