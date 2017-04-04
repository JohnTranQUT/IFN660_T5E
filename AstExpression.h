#pragma once
#include <vector>
#include <AstNode.h>

using namespace std;

class Expression : public Node {
public:
	virtual ~Expression() = default;
	virtual void dump(int = 0) = 0;
};

class Identifier : public Expression {
	vector<Node*> next;
	char *identifier;
public:
	explicit Identifier(char *);
	void dump(int = 0) override;
};

class DecimalLiteral : public Expression {
	vector<Node*> next;
	double decimalLiteral;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
};

class Literal : public Expression {
	vector<Node*> next;
	Expression *decimalLiteral;
public:
	explicit Literal(Expression *);
	void dump(int = 0) override;
};

class IdentifierReference : public Expression {
	vector<Node*> next;
	Expression *identifier;
public:
	explicit IdentifierReference(Expression *);
	void dump(int = 0) override;
};

class AssignmentExpression : public Expression {
	vector<Node*> next;
	Expression *identifierReference;
	Expression *literal;
public:
	explicit AssignmentExpression(Expression *, Expression *);
	void dump(int = 0) override;
};
