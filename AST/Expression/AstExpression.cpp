#include <string>
#include <typeinfo>
#include <AST/Node/AstNode.h>
#include <AST/Expression/AstExpression.h>
using namespace std;
IdentifierName::IdentifierName(char *_LHS) : LHS(_LHS) { }

void IdentifierName::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void IdentifierName::genCode()
{
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void DecimalLiteral::genCode()
{
}

Identifier::Identifier(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void Identifier::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void Identifier::genCode()
{
}

NumericLiteral::NumericLiteral(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void NumericLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void NumericLiteral::genCode()
{
}

Literal::Literal(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void Literal::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void Literal::genCode()
{
}

IdentifierReference::IdentifierReference(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void IdentifierReference::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void IdentifierReference::genCode()
{
}

PrimaryExpression::PrimaryExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void PrimaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void PrimaryExpression::genCode()
{
}

MemberExpression::MemberExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void MemberExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void MemberExpression::genCode()
{
}

NewExpression::NewExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void NewExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void NewExpression::genCode()
{
}

LeftHandSideExpression::LeftHandSideExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LeftHandSideExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void LeftHandSideExpression::genCode()
{
}

UpdateExpression::UpdateExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void UpdateExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void UpdateExpression::genCode()
{
}

UnaryExpression::UnaryExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void UnaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void UnaryExpression::genCode()
{
}

ExponentiationExpression::ExponentiationExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ExponentiationExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void ExponentiationExpression::genCode()
{
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void MultiplicativeExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void MultiplicativeExpression::genCode()
{
}


AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr), op(nullptr) {
	next.push_back(LHS);
}

AdditiveExpression::AdditiveExpression(Expression *_LHS, Expression *_RHS, char *_op) :	LHS(_LHS),
																						RHS(_RHS),
																						op(_op) {
	next.push_back(LHS);
	next.push_back(RHS);
}

void AdditiveExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void AdditiveExpression::genCode()
{
}

ShiftExpression::ShiftExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ShiftExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void ShiftExpression::genCode()
{
}

RelationalExpression::RelationalExpression(Expression *_LHS) : LHS(_LHS),
                                                               RHS(nullptr),
                                                               op(nullptr) {
	next.push_back(LHS);
}

RelationalExpression::RelationalExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS),
                                                                                            RHS(_RHS),
                                                                                            op(_op) {
	vector<Node *> components = { LHS, RHS };
	auto container = new Container(components, "('" + string(op) + "' OP)");
	next.push_back(container);
}

void RelationalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void RelationalExpression::genCode()
{
}

EqualityExpression::EqualityExpression(Expression *_LHS) : LHS(_LHS),
                                                           RHS(nullptr),
                                                           op(nullptr) {
	next.push_back(LHS);
}

EqualityExpression::EqualityExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS),
                                                                                        RHS(_RHS),
                                                                                        op(_op) {
	vector<Node *> components = { LHS, RHS };
	auto container = new Container(components, "('" + string(op) + "' OP)");
	next.push_back(container);
}

void EqualityExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void EqualityExpression::genCode()
{
}

BitwiseANDExpression::BitwiseANDExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void BitwiseANDExpression::genCode()
{
}

BitwiseXORExpression::BitwiseXORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseXORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void BitwiseXORExpression::genCode()
{
}

BitwiseORExpression::BitwiseORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void BitwiseORExpression::genCode()
{
}

LogicalANDExpression::LogicalANDExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LogicalANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void LogicalANDExpression::genCode()
{
}

LogicalORExpression::LogicalORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LogicalORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void LogicalORExpression::genCode()
{
}

ConditionalExpression::ConditionalExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ConditionalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void ConditionalExpression::genCode()
{
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS),
                                                                                 RHS(_RHS) {
	next.push_back(LHS);
	next.push_back(RHS);
}

AssignmentExpression::AssignmentExpression(Expression *_LHS) : LHS(_LHS),
                                                               RHS(nullptr) {
	next.push_back(LHS);
}

void AssignmentExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void AssignmentExpression::genCode()
{
}
