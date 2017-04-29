#include <string>
#include <typeinfo>
#include "AST/AstNode.h"
#include "AST/AstExpression.h"

using namespace std;

IdentifierName::IdentifierName(char *_LHS) : LHS(_LHS) { }

void IdentifierName::dump(int indent) {
	//fix me
	label(indent, "IdentifierName %s\n",LHS);
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	
}

Identifier::Identifier(Expression *_LHS) : LHS(_LHS) {
	
}

void Identifier::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

NumericLiteral::NumericLiteral(Expression *_LHS) : LHS(_LHS) {
	
}

void NumericLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

Literal::Literal(Expression *_LHS) : LHS(_LHS) {
	
}

void Literal::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

IdentifierReference::IdentifierReference(Expression *_LHS) : LHS(_LHS) {
	
}

void IdentifierReference::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	
}

PrimaryExpression::PrimaryExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void PrimaryExpression::dump(int indent) {
	label(indent, "PrimaryExpression\n");
	LHS->dump(indent = 1);
	
}

MemberExpression::MemberExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void MemberExpression::dump(int indent) {
	label(indent, "MemberExpression\n");
	LHS->dump(indent = 1);
	
}

NewExpression::NewExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void NewExpression::dump(int indent) {
	label(indent, "NewExpression\n");
	LHS->dump(indent + 1);
	
}

LeftHandSideExpression::LeftHandSideExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void LeftHandSideExpression::dump(int indent) {
	label(indent, "LeftHandSideExpression\n");
	LHS->dump(indent + 1);
	
}

UpdateExpression::UpdateExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void UpdateExpression::dump(int indent) {
	label(indent, "UpdateExpression\n");
	LHS->dump(indent + 1);
	
}

UnaryExpression::UnaryExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void UnaryExpression::dump(int indent) {
	label(indent, "UnaryExpression\n");
	LHS->dump(indent + 1);
	
}

ExponentiationExpression::ExponentiationExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void ExponentiationExpression::dump(int indent) {
	label(indent, "ExponentiationExpression\n");
	LHS->dump(indent + 1);
	
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void MultiplicativeExpression::dump(int indent) {
	label(indent, "MultiplicativeExpression\n");
	LHS->dump(indent + 1);
	
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void AdditiveExpression::dump(int indent) {
	label(indent, "AdditiveExpression\n");
	LHS->dump(indent + 1);
	
}

ShiftExpression::ShiftExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void ShiftExpression::dump(int indent) {
	label(indent, "ShiftExpression\n");
	LHS->dump(indent + 1);
	
}

RelationalExpression::RelationalExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr), op(nullptr) {
	
}

RelationalExpression::RelationalExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS), RHS(_RHS), op(_op) {
	
	
}

void RelationalExpression::dump(int indent) {
	label(indent, "RelationalExpression %s\n", op);
	LHS->dump(indent + 1, "lhs");
	RHS->dump(indent + 1, "rhs");
}

EqualityExpression::EqualityExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr), op(nullptr) {
	
}

EqualityExpression::EqualityExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS), RHS(_RHS), op(_op) {
	
	
}

void EqualityExpression::dump(int indent) {
	label(indent, "EqualityExpression %s\n",op);
	LHS->dump(indent + 1,"lhs");
	RHS->dump(indent + 1, "rhs");
	
}

BitwiseANDExpression::BitwiseANDExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void BitwiseANDExpression::dump(int indent) {
	label(indent, "BitwiseANDExpression\n");
	LHS->dump(indent + 1);
	
}

BitwiseXORExpression::BitwiseXORExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void BitwiseXORExpression::dump(int indent) {
	label(indent, "BitwiseXORExpression\n");
	LHS->dump(indent + 1);
	
}

BitwiseORExpression::BitwiseORExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void BitwiseORExpression::dump(int indent) {
	label(indent, "BitwiseORExpression\n");
	LHS->dump(indent + 1);
	
}

LogicalANDExpression::LogicalANDExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void LogicalANDExpression::dump(int indent) {
	label(indent, "LogicalANDExpression\n");
	LHS->dump(indent + 1);
	
}

LogicalORExpression::LogicalORExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void LogicalORExpression::dump(int indent) {
	label(indent, "LogicalORExpression\n");
	LHS->dump(indent + 1);
	
}

ConditionalExpression::ConditionalExpression(Expression *_LHS) : LHS(_LHS) {
	
}

void ConditionalExpression::dump(int indent) {
	label(indent, "ConditionalExpression\n");
	LHS->dump(indent + 1);
	
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	
}

AssignmentExpression::AssignmentExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr) {
	
}

void AssignmentExpression::dump(int indent) {
	label(indent, "AssignmentExpression\n");
	LHS->dump(indent + 1, "lhs");
	RHS->dump(indent + 1, "rhs");
}
