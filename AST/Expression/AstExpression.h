#pragma once
#include <vector>
#include <AST/Node/AstNode.h>
using namespace std;

class Expression : public Node {
public:
	virtual ~Expression() = default;
	void dump(int = 0) override = 0;
	int eval(int, FILE*)override {	return 0;};
};

class IdentifierName : public Expression {
	char *LHS;
public:
	explicit IdentifierName(char *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class DecimalLiteral : public Expression {
	double LHS;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class Identifier : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit Identifier(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class NumericLiteral : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit NumericLiteral(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};
class StringLiteral : public Expression {
	string LHS;
public:
	explicit StringLiteral(char *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class Literal : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit Literal(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class IdentifierReference : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit IdentifierReference(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class PrimaryExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit PrimaryExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class MemberExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit MemberExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class NewExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit NewExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class LeftHandSideExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit LeftHandSideExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class UpdateExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit UpdateExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class UnaryExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit UnaryExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class ExponentiationExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit ExponentiationExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class MultiplicativeExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit MultiplicativeExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class AdditiveExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit AdditiveExpression(Expression *);
	explicit AdditiveExpression(Expression *, Expression *, char*);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class ShiftExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit ShiftExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class RelationalExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit RelationalExpression(Expression *);
	explicit RelationalExpression(Expression *, Expression *, char *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class EqualityExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit EqualityExpression(Expression *);
	explicit EqualityExpression(Expression *, Expression *, char *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class BitwiseANDExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit BitwiseANDExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class BitwiseXORExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit BitwiseXORExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class BitwiseORExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit BitwiseORExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class LogicalANDExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit LogicalANDExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class LogicalORExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit LogicalORExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class ConditionalExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
public:
	explicit ConditionalExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};

class AssignmentExpression : public Expression {
	vector<Node*> next;
	Expression *LHS;
	Expression *RHS;
public:
	explicit AssignmentExpression(Expression *, Expression *);
	explicit AssignmentExpression(Expression *);
	void dump(int = 0) override;
	int eval(int, FILE*)override;
};
