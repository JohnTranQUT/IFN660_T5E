#pragma once
#include <cstdio>
#include <vector>

using namespace std;
class Node {
public:
	static vector<Node*> history;
	virtual ~Node() = default;
	virtual void dump(int = 0) = 0;
	virtual int getIndent() = 0;
	virtual void setIndent(int) = 0;
	static void indentation(int);
};

class Identifier : public Node {
	int indent = 0;
	vector<Node*> next;
	char* identifier;
public:
	explicit Identifier(char*);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};

class DecimalLiteral : public Node {
	int indent = 0;
	vector<Node*> next;
	double decimalLiteral;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};

class AssignmentExpression : public Node {
	int indent = 0;
	vector<Node*> next;
	Identifier* identifier;
	DecimalLiteral* decimalLiteral;
public:
	AssignmentExpression(Identifier*, DecimalLiteral*);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};

class ExpressionStatement : public Node {
	int indent = 0;
	vector<Node*> next;
	AssignmentExpression* assignmentExpression;
public:
	explicit ExpressionStatement(AssignmentExpression*);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};

class Statement : public Node {
	int indent = 0;
	vector<Node*> next;
	ExpressionStatement* expressionStatement;
public:
	explicit Statement(ExpressionStatement*);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};

class Script : public Node {
	int indent = 0;
	vector<Node*> next;
	Statement* statement;
public:
	explicit Script(Statement*);
	void dump(int = 0) override;
	int getIndent() override;
	void setIndent(int) override;
};