#pragma once
#include "AST/AstNode.h"

using namespace std;

class Expression : public Node {
public:
	explicit Expression() {}
};


class IdentifierName : public Expression {
	char *LHS;
public:
	explicit IdentifierName(char *LHS):LHS(LHS){}
	void dump(int indent) override {
		label(indent, "IdentifierName %s\n", LHS);
	}
};

class DecimalLiteral : public Expression {
	double value;
public:
	explicit DecimalLiteral(double value):value(value){}
	void dump(int indent) override{
		label(indent, "DecimalLiteral %f\n", value);
	}
};

class Identifier : public Expression {
	Expression *LHS;
public:
	explicit Identifier(Expression *LHS):LHS(LHS){};
	void dump(int indent) override {
		label(indent, "Identifier\n");
		LHS->dump(indent + 1);
	}
};

class NumericLiteral : public Expression {
	Expression *LHS;
public:
	explicit NumericLiteral(Expression *LHS):LHS(LHS){};
	void dump(int indent) override {
		label(indent, "NumericLiteral\n");
		LHS->dump(indent + 1);
	}
};

class Literal : public Expression {
	Expression *LHS;
public:
	explicit Literal(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "Literal\n");
		LHS->dump(indent + 1);
	}
};

class IdentifierReference : public Expression {
	Expression *LHS;
public:
	explicit IdentifierReference(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "IdentifierReference\n");
		LHS->dump(indent + 1);
	}
};

class PrimaryExpression : public Expression {
	Expression *LHS;
public:
	explicit PrimaryExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "PrimaryExpression\n");
		LHS->dump(indent + 1);
	}
};

class MemberExpression : public Expression {
	Expression *LHS;
public:
	explicit MemberExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "MemberExpression\n");
		LHS->dump(indent + 1);
	}
};

class NewExpression : public Expression {
	Expression *LHS;
public:
	explicit NewExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "NewExpression\n");
		LHS->dump(indent + 1);
	}
};

class LeftHandSideExpression : public Expression {
	Expression *LHS;
public:
	explicit LeftHandSideExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "LeftHandSideExpression\n");
		LHS->dump(indent + 1);
	}
};

class UpdateExpression : public Expression {
	Expression *LHS;
public:
	explicit UpdateExpression(Expression *LHS):LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "UpdateExpression\n");
		LHS->dump(indent + 1);
	}
};

class UnaryExpression : public Expression {
	Expression *LHS;
public:
	explicit UnaryExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override 	{
		label(indent, "UnaryExpression\n");
		LHS->dump(indent + 1);
	}
};

class ExponentiationExpression : public Expression {
	Expression *LHS;
public:
	explicit ExponentiationExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "ExponentiationExpression\n");
		LHS->dump(indent + 1);
	}
};

class MultiplicativeExpression : public Expression {
	Expression *LHS;
public:
	explicit MultiplicativeExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "MultiplicativeExpression\n");
		LHS->dump(indent + 1);
	}
};

class AdditiveExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char op;
public:
	explicit AdditiveExpression(Expression *LHS) :LHS(LHS) {};
	explicit AdditiveExpression(Expression *LHS, Expression *RHS, char op) :LHS(LHS), RHS(RHS), op(op){}
	void dump(int indent) override {
		label(indent, "AdditiveExpression %c\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr) {
			RHS->dump(indent + 1, "rhs");
		}
	}
};

class ShiftExpression : public Expression {
	Expression *LHS;
public:
	explicit ShiftExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "ShiftExpression\n");
		LHS->dump(indent + 1);
	}
};

class RelationalExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit RelationalExpression(Expression *LHS):LHS(LHS),RHS(nullptr),op(nullptr) {};
	explicit RelationalExpression(Expression *LHS, Expression *RHS, char *op) :LHS(LHS), RHS(RHS), op(op) {}
	void dump(int indent) override {
		label(indent, "RelationalExpression %s\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}
};

class EqualityExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit EqualityExpression(Expression *LHS):LHS(LHS), RHS(nullptr),op(nullptr){}
	explicit EqualityExpression(Expression *LHS, Expression *RHS, char *op) :LHS(LHS), RHS(RHS), op(op) {}
	void dump(int indent) override {
		label(indent, "EqualityExpression %s\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}
};

class BitwiseANDExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseANDExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "BitwiseANDExpression\n");
		LHS->dump(indent + 1);
	}
};

class BitwiseXORExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseXORExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "BitwiseXORExpression\n");
		LHS->dump(indent + 1);
	}
};

class BitwiseORExpression : public Expression {
	Expression *LHS;
public:
	explicit BitwiseORExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "BitwiseORExpression\n");
		LHS->dump(indent + 1);
	}
};

class LogicalANDExpression : public Expression {
	Expression *LHS;
public:
	explicit LogicalANDExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "LogicalANDExpression\n");
		LHS->dump(indent + 1);
	}
};

class LogicalORExpression : public Expression {
	Expression *LHS;
public:
	explicit LogicalORExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "LogicalORExpression\n");
		LHS->dump(indent + 1);
	}
};

class ConditionalExpression : public Expression {
	Expression *LHS;
public:
	explicit ConditionalExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "ConditionalExpression\n");
		LHS->dump(indent + 1);
	}
};

class AssignmentExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
public:
	explicit AssignmentExpression(Expression *LHS, Expression *RHS):LHS(LHS),RHS(RHS){};
	explicit AssignmentExpression(Expression *LHS):LHS(LHS),RHS(nullptr);
	void dump(int indent) override {
		label(indent, "AssignmentExpression\n");
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}
};
