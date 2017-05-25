#include <string>
#include <typeinfo>
#include <AST/AstNode.h>
#include <AST/AstExpression.h>
#include <iostream>
#include <fstream>

using namespace std;
extern int CounterLabel;
extern ofstream SaveFile;

IdentifierName::IdentifierName(char *_LHS) : LHS(_LHS) { }

void IdentifierName::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void IdentifierName::Gecode()
{
	push();
	auto r = reg.back();
	SaveFile << "auto r" << r << " = \"" << LHS << "\";" << endl;
	
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void DecimalLiteral::Gecode()
{
	push();
	auto r = reg.back();
	SaveFile << "auto r" << r << " = new NumberType(" << LHS << ");" << endl;
	
}

StringLiteral::StringLiteral(string _LHS) : LHS(_LHS) { }

void StringLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + LHS + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void StringLiteral::Gecode()
{
	push();
	auto r = reg.back();
	SaveFile << "auto r" << r << " = new StringType(" << LHS << ");" << endl;
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

void Identifier::Gecode()
{
	for (auto s : next)
	{
		s->Gecode();
	}
	auto x = reg.back();
	reg.pop_back();
	push();
	auto r = reg.back();
	SaveFile << "auto r" << r << " = ResolveBinding(r" << x << ", r0);" << endl;
	
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

void NumericLiteral::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void Literal::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void IdentifierReference::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void PrimaryExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void MemberExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void NewExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void LeftHandSideExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void UpdateExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void UnaryExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void ExponentiationExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void MultiplicativeExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

AdditiveExpression::AdditiveExpression(Expression *_LHS , Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	next.push_back(RHS);
	next.push_back(LHS);
}

void AdditiveExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void AdditiveExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
	if (next.size() > 1)
	{
		auto ls = reg.back();
		reg.pop_back();
		auto rs = reg.back();
		reg.pop_back();
		push();
		auto r = reg.back();
		SaveFile << "auto r" << r << " = AdditiveOperator(r" << ls << ",r" << rs << ");" << endl;
	}
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

void ShiftExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
}

RelationalExpression::RelationalExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr), op(nullptr) {
	next.push_back(LHS);
}

RelationalExpression::RelationalExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS), RHS(_RHS), op(_op) {
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

void RelationalExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
}

EqualityExpression::EqualityExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr), op(nullptr) {
	next.push_back(LHS);
}

EqualityExpression::EqualityExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS), RHS(_RHS), op(_op) {
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

void EqualityExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void BitwiseANDExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void BitwiseXORExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void BitwiseORExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void LogicalANDExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void LogicalORExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
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

void ConditionalExpression::Gecode()
{
	for (auto i : next) {
		i->Gecode();
	}
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	next.push_back(RHS);
	next.push_back(LHS);
}

AssignmentExpression::AssignmentExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr) {
	next.push_back(LHS);
}

void AssignmentExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void AssignmentExpression::Gecode()
{
	for (auto s : next)
	{
		s->Gecode();
	}
	if (next.size() > 1)
	{
		auto ls = reg.back();
		reg.pop_back();
		auto rs = reg.back();
		reg.pop_back();
		push();
		auto r = reg.back();
		SaveFile << "auto r" << r << " = AssignmentOperator(r" << ls << ",r" << rs << ");" << endl;
	}
}

