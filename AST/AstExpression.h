#pragma once
#include "AST/AstNode.h"

using namespace std;

class Expression : public Node {

};

class IdentifierName : public Expression {
	char *LHS;
public:
	explicit IdentifierName(char *);
	void dump(int = 0) override;
};

class DecimalLiteral : public Expression {
	double LHS;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
};

class Identifier : public Expression {
	Expression *LHS;
public:
	explicit Identifier(Expression *);
	void dump(int = 0) override;
};

class NumericLiteral : public Expression {
	Expression *LHS;
public:
	explicit NumericLiteral(Expression *);
	void dump(int = 0) override;
};

class Literal : public Expression {
	Expression *LHS;
public:
	explicit Literal(Expression *);
	void dump(int = 0) override;
};

class IdentifierReference : public Expression {
	Expression *LHS;
public:
	explicit IdentifierReference(Expression *);
	void dump(int = 0) override;
};

class PrimaryExpression : public Expression {
	Expression *LHS;
public:
	explicit PrimaryExpression(Expression *);
	void dump(int = 0) override;
};

class MemberExpression : public Expression {
	Expression *LHS;
public:
	explicit MemberExpression(Expression *);
	void dump(int = 0) override;
};

class NewExpression : public Expression {
	Expression *LHS;
public:
	explicit NewExpression(Expression *);
	void dump(int = 0) override;
};

class LeftHandSideExpression : public Expression {
	Expression *LHS;
public:
	explicit LeftHandSideExpression(Expression *);
	void dump(int = 0) override;
};

class UpdateExpression : public Expression {
	Expression *LHS;
public:
	explicit UpdateExpression(Expression *);
	void dump(int = 0) override;
};

class UnaryExpression : public Expression {
	Expression *LHS;
public:
	explicit UnaryExpression(Expression *);
	void dump(int = 0) override;
};

class ExponentiationExpression : public Expression {
	Expression *LHS;
public:
	explicit ExponentiationExpression(Expression *);
	void dump(int = 0) override;
};

class MultiplicativeExpression : public Expression {
	Expression *LHS;
public:
	explicit MultiplicativeExpression(Expression *);
	void dump(int = 0) override;
};

class AdditiveExpression : public Expression {
	Expression *LHS;
public:
	explicit AdditiveExpression(Expression *);
	void dump(int = 0) override;
};

class ShiftExpression : public Expression {
	Expression *LHS;
public:
	explicit ShiftExpression(Expression *);
	void dump(int = 0) override;
};

class RelationalExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit RelationalExpression(Expression *);
	explicit RelationalExpression(Expression *, Expression *, char *);
	void dump(int = 0) override;
};

class EqualityExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit EqualityExpression(Expression *);
	explicit EqualityExpression(Expression *, Expression *, char *);
	void dump(int = 0) override;
};

class BitwiseANDExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseANDExpression(Expression *);
	void dump(int = 0) override;
};

class BitwiseXORExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseXORExpression(Expression *);
	void dump(int = 0) override;
};

class BitwiseORExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseORExpression(Expression *);
	void dump(int = 0) override;
};

class LogicalANDExpression : public Expression {
	Expression *LHS;
public:
	explicit LogicalANDExpression(Expression *);
	void dump(int = 0) override;
};

class LogicalORExpression : public Expression {
	Expression *LHS;
public:
	explicit LogicalORExpression(Expression *);
	void dump(int = 0) override;
};

class ConditionalExpression : public Expression {
	Expression *LHS;
public:
	explicit ConditionalExpression(Expression *);
	void dump(int = 0) override;
};

class AssignmentExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
public:
	explicit AssignmentExpression(Expression *, Expression *);
	explicit AssignmentExpression(Expression *);
	void dump(int = 0) override;
};
