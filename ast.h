#pragma once
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	virtual ~Node() = default;
	virtual void dump(int = 0) = 0;
	static void dump(string, int);
	static void indentation(int);
};

class Identifier : public Node {
	vector<Node*> next;
	char *identifier;
public:
	explicit Identifier(char *);
	void dump(int = 0) override;
};

class DecimalLiteral : public Node {
	vector<Node*> next;
	double decimalLiteral;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
};

class AssignmentExpression : public Node {
	vector<Node*> next;
	Identifier *identifier;
	DecimalLiteral *decimalLiteral;
public:
	AssignmentExpression(Identifier *, DecimalLiteral *);
	void dump(int = 0) override;
};

class Expression : public Node {
	vector<Node*> next;
	AssignmentExpression *assignmentExpression;
public:
	explicit Expression(AssignmentExpression *);
	void dump(int = 0) override;
};

class ExpressionStatement : public Node {
	vector<Node*> next;
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int = 0) override;
};

class Statement : public Node {
	vector<Node*> next;
	ExpressionStatement *expressionStatement;
public:
	explicit Statement(ExpressionStatement *);
	void dump(int = 0) override;
};

class Script : public Node {
	vector<Node*> next;
	Statement *statement;
public:
	explicit Script(Statement *);
	void dump(int = 0) override;
};
