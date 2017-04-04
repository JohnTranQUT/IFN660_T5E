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

class Container : public Node {
	vector<Node*> next;
	string name;
public:
	explicit Container(vector<Node*>, string);
	void dump(int = 0) override;
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

class Literal : public Node {
	vector<Node*> next;
	DecimalLiteral *decimalLiteral;
public:
	explicit Literal(DecimalLiteral *);
	void dump(int = 0) override;
};

class IdentifierReference : public Node {
	vector<Node*> next;
	Identifier *identifier;
public:
	explicit IdentifierReference(Identifier *);
	void dump(int = 0) override;
};

class AssignmentExpression : public Node {
	vector<Node*> next;
	IdentifierReference *identifierReference;
	Literal *literal;
public:
	explicit AssignmentExpression(IdentifierReference *, Literal *);
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
