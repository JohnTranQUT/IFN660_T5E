#pragma once
#include "AST/AstScript.h"
#include "parser.h"

using namespace std;
extern int CounterLabel;


class IdentifierName : public Expression {
	char *LHS;
public:
	explicit IdentifierName(char *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "IdentifierName %s\n", LHS);
	}

	int GenCode(FILE* file) override {
		emit(file, "auto* r%d = ResolveBinding(\"%s\", globalenv);", CounterLabel, LHS);
		return CounterLabel++;
	};
};

class DecimalLiteral : public Expression {
	double value;
public:
	explicit DecimalLiteral(double value) :value(value) {}
	void dump(int indent) override {
		label(indent, "DecimalLiteral %f\n", value);
	}
	int GenCode(FILE* file) override {
		emit(file, "auto* r%d = new NumberType(%f);", CounterLabel, value);
		return CounterLabel++;
	};
};

class Identifier : public Expression {
	Expression *LHS;
public:
	explicit Identifier(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "Identifier\n");
		LHS->dump(indent + 1);
	}
	int GenCode(FILE* file) override {
		return LHS->GenCode(file);
	}

};

class NumericLiteral : public Expression {
	Expression *LHS;
public:
	explicit NumericLiteral(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "NumericLiteral\n");
		LHS->dump(indent + 1);
	}
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {
		return LHS->GenCode(file);;
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
	int GenCode(FILE* file) override {
		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
	}
};

class UpdateExpression : public Expression {
	Expression *LHS;
	int op;
public:
	explicit UpdateExpression(Expression *LHS) :LHS(LHS) {}
	explicit UpdateExpression(Expression *LHS, int op) :LHS(LHS), op(op) {}
	void dump(int indent) override {
		label(indent, "UpdateExpression: %d\n", op);
		LHS->dump(indent + 1);
	}
	int GenCode(FILE* file) override {
		if (op == 0)
		{
			return LHS->GenCode(file);
		}
		else
		{
			int lrefno = LHS->GenCode(file);
			switch (op)
			{
			case 310:
				emit(file, "auto* r%d = increment(r%d);", CounterLabel, lrefno);
				CounterLabel++;
				break;
			default:
				break;
			}
			return CounterLabel;
		}

	}
};

class UnaryExpression : public Expression {
	Expression *LHS;
public:
	explicit UnaryExpression(Expression *LHS) :LHS(LHS) {};
	void dump(int indent) override {
		label(indent, "UnaryExpression\n");
		LHS->dump(indent + 1);
	}
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
	}
};

class MultiplicativeExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char op;
public:
	explicit MultiplicativeExpression(Expression *LHS) :LHS(LHS),RHS(nullptr) {
	};
	explicit MultiplicativeExpression(Expression *LHS, Expression *RHS, char op) :LHS(LHS), RHS(RHS), op(op) {};
	void dump(int indent) override {
		label(indent, "MultiplicativeExpression %c\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr) {
			RHS->dump(indent + 1, "rhs");
		}
	}
	int GenCode(FILE* file) override {
		if (RHS == nullptr)
		{
			return LHS->GenCode(file);
		}
		else
		{
			int lrefno = LHS->GenCode(file);
			int rrefno = RHS->GenCode(file);
			if (op == '*') {
				emit(file, "auto* r%d = multiplication(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
				

			else if (op == '/') {
				emit(file, "auto* r%d = division(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
				
			return CounterLabel;
		}
	}
};

class AdditiveExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char op;
public:
	explicit AdditiveExpression(Expression *LHS) :LHS(LHS), RHS(nullptr){};
	explicit AdditiveExpression(Expression *LHS, Expression *RHS, char op) :LHS(LHS), RHS(RHS), op(op) {}
	void dump(int indent) override {
		label(indent, "AdditiveExpression %c\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr) {
			RHS->dump(indent + 1, "rhs");
		}
	}
	int GenCode(FILE* file) override {
		if (RHS == nullptr)
		{
			return LHS->GenCode(file);
		}
		else
		{
			int lrefno = LHS->GenCode(file);
			int rrefno = RHS->GenCode(file);
			if (op == '+') {
				emit(file, "auto* r%d = additiveOperator(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
			else if (op == '-') {
				emit(file, "auto* r%d = subtractiveOperator(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
				
			return CounterLabel;
		}

	};
};

class ShiftExpression : public Expression {
	Expression *LHS;
public:
	explicit ShiftExpression(Expression *LHS) :LHS(LHS) {}
	void dump(int indent) override {
		label(indent, "ShiftExpression\n");
		LHS->dump(indent + 1);
	}
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
	}
};

class RelationalExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit RelationalExpression(Expression *LHS) :LHS(LHS), RHS(nullptr), op(nullptr) {};
	explicit RelationalExpression(Expression *LHS, Expression *RHS, char *op) :LHS(LHS), RHS(RHS), op(op) {}
	void dump(int indent) override {
		label(indent, "RelationalExpression %s\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}
	int GenCode(FILE* file) override {
		if (RHS == nullptr)
		{
			return LHS->GenCode(file);
		}
		else
		{
			int lrefno = LHS->GenCode(file);
			int rrefno = RHS->GenCode(file);
			if (strcmp(op, "<") == 0)
			{
				emit(file, "auto* r%d = lessThan(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
			else  if (strcmp(op, "<=") == 0)
			{
				emit(file, "auto* r%d = lessOrEQual(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
			else  if (strcmp(op, ">") == 0)
			{
				emit(file, "auto* r%d = greaterThan(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
			else  if (strcmp(op, ">=") == 0)
			{
				emit(file, "auto* r%d = greaterOrEQual(r%d,r%d);", CounterLabel, lrefno, rrefno);
				CounterLabel++;
			}
			return CounterLabel;
		}
	}
};

class EqualityExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
	char *op;
public:
	explicit EqualityExpression(Expression *LHS) :LHS(LHS), RHS(nullptr), op(nullptr) {}
	explicit EqualityExpression(Expression *LHS, Expression *RHS, char *op) :LHS(LHS), RHS(RHS), op(op) {}
	void dump(int indent) override {
		label(indent, "EqualityExpression %s\n", op);
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
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
	int GenCode(FILE* file) override {

		return LHS->GenCode(file);
	}
};

class AssignmentExpression : public Expression {
	Expression *LHS;
	Expression *RHS;
public:
	explicit AssignmentExpression(Expression *LHS, Expression *RHS) :LHS(LHS), RHS(RHS) {};
	explicit AssignmentExpression(Expression *LHS) :LHS(LHS), RHS(nullptr) {};
	void dump(int indent) override {
		label(indent, "AssignmentExpression\n");
		LHS->dump(indent + 1, "lhs");
		if (RHS != nullptr)
		{
			RHS->dump(indent + 1, "rhs");
		}
	}

	int GenCode(FILE* file) {
		if (RHS == nullptr)
		{
			return LHS->GenCode(file);
		}
		else
		{
			int lrefno = LHS->GenCode(file);
			int rrefno = RHS->GenCode(file);
			emit(file, "auto* r%d = assignment(r%d,r%d);", CounterLabel, lrefno, rrefno);
			return CounterLabel++;
		}

	};
};
