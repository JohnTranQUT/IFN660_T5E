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

class Statement : public Node {
public:
	virtual ~Statement() = default;
	virtual void dump(int = 0) = 0;
};

class Expression : public Node {
public:
	virtual ~Expression() = default;
	virtual void dump(int = 0) = 0;
};

class Container : public Node {
	vector<Node*> next;
	string name;
public:
	explicit Container(vector<Node*>, string);
	void dump(int = 0) override;
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
	char* decimalLiteral;
public:
	explicit DecimalLiteral(char*);
	void dump(int = 0) override;
};

class Literal : public Expression {
	vector<Node*> next;
	DecimalLiteral *decimalLiteral;
public:
	explicit Literal(DecimalLiteral *);
	void dump(int = 0) override;
};

class IdentifierReference : public Expression {
	vector<Node*> next;
	Identifier *identifier;
public:
	explicit IdentifierReference(Identifier *);
	void dump(int = 0) override;
};

class AssignmentExpression : public Expression {
	vector<Node*> next;
	IdentifierReference *identifierReference;
	Literal *literal;
public:
	explicit AssignmentExpression(IdentifierReference *, Literal *);
	void dump(int = 0) override;
};


class ExpressionStatement : public Statement {
	vector<Node*> next;
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int = 0) override;
};

class Script : public Node {
	vector<Node*> next;
	Statement *statement;
public:
	explicit Script(Statement *);
	void dump(int = 0) override;
};
