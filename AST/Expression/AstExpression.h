#pragma once
#include <vector>
#include "AST/Node/AstNode.h"
using namespace std;

class Expression : public Node {
public:
	virtual ~Expression() = default;
	void dump(int = 0) override = 0;
	void evaluate() override = 0;
	void instantiate() override = 0;
};

class IdentifierName : public Expression {
	char *LHS;
public:
	explicit IdentifierName(char *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class DecimalLiteral : public Expression {
	double LHS;
public:
	explicit DecimalLiteral(double);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class Identifier : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit Identifier(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class BooleanLiteral : public Expression {
	vector<Node*> children;
	bool LHS;
public:
	explicit BooleanLiteral(bool);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class StringLiteral : public Expression {
	vector<Node*> children;
	string LHS;
public:
	explicit StringLiteral(string);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class NullLiteral : public Expression {
public:
	explicit NullLiteral() { };
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class NumericLiteral : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit NumericLiteral(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class Literal : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit Literal(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class IdentifierReference : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit IdentifierReference(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class BindingIdentifier : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit BindingIdentifier(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class PrimaryExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit PrimaryExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class MemberExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit MemberExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class NewExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit NewExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class LeftHandSideExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit LeftHandSideExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class UpdateExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit UpdateExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class UnaryExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit UnaryExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ExponentiationExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	Expression *RHS;
public:
	explicit ExponentiationExpression(Expression *);
	explicit ExponentiationExpression(Expression *, Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class MultiplicativeExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	string OP;
	Expression *RHS;
public:
	explicit MultiplicativeExpression(Expression *);
	explicit MultiplicativeExpression(Expression *, string, Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class AdditiveExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	string OP;
	Expression *RHS;
public:
	explicit AdditiveExpression(Expression *);
	explicit AdditiveExpression(Expression *, string, Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ShiftExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit ShiftExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class RelationalExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	string OP;
	Expression *RHS;
public:
	explicit RelationalExpression(Expression *);
	explicit RelationalExpression(Expression *, string, Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class EqualityExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	Expression *RHS;
	string OP;
public:
	explicit EqualityExpression(Expression *);
	explicit EqualityExpression(Expression *, string, Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class BitwiseANDExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit BitwiseANDExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class BitwiseXORExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit BitwiseXORExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class BitwiseORExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit BitwiseORExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class LogicalANDExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit LogicalANDExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class LogicalORExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit LogicalORExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class ConditionalExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit ConditionalExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class AssignmentExpression : public Expression {
	vector<Node*> children;
	Expression *LHS;
	Expression *RHS;
public:
	explicit AssignmentExpression(Expression *, Expression *);
	explicit AssignmentExpression(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class Initializer : public Expression {
	vector<Node*> children;
	Expression *LHS;
public:
	explicit Initializer(): LHS(nullptr) { } ;
	explicit Initializer(Expression *);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};

class Initializer_opt : public Expression { };
