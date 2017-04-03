#pragma once
#include <cstdio>

class Node {
public:
	virtual ~Node() = default;
	virtual void dump() = 0;
};

class Identifier : public Node {
	char* identifier;
public:
	explicit Identifier(char*);
	void dump() override;
};

class DecimalLiteral : public Node {
	double decimalLiteral;
public:
	explicit DecimalLiteral(double);
	void dump() override;
};

class AssignmentExpression : public Node {
	Identifier* identifier;
	DecimalLiteral* decimalLiteral;
public:
	AssignmentExpression(Identifier*, DecimalLiteral*);
	void dump() override;
};

class ExpressionStatement : public Node {
	AssignmentExpression* assignmentExpression;
public:
	explicit ExpressionStatement(AssignmentExpression*);
	void dump() override;
};

class Statement : public Node {
	ExpressionStatement* expressionStatement;
public:
	explicit Statement(ExpressionStatement*);
	void dump() override;
};

class Script : public Node {
	Statement* statement;
public:
	explicit Script(Statement*);
	void dump() override;
};