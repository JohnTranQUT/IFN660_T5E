#include "AST/Expression/AstExpression.h"
#include <string>
#include <typeinfo>
#include "AST/Node/AstNode.h"
#include "AST/_Helpers/_Helpers.h"

using namespace std;
IdentifierName::IdentifierName(char *_LHS) : LHS(_LHS) { }

void IdentifierName::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void IdentifierName::evaluate() {
	emit(string("new StringType(\"") + LHS + string("\");"));
}

void IdentifierName::instantiate() {
	emit(string("new StringType(\"") + LHS + string("\");"));
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + _TrimDecimal(to_string(LHS)) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void DecimalLiteral::evaluate() {
	emit(string("new NumberType(") + _TrimDecimal(to_string(LHS)) + string(");"));
}

void DecimalLiteral::instantiate() { }

Identifier::Identifier(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void Identifier::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void Identifier::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	auto ident = refs.back();
	refs.pop_back();

	emit(string("ResolveBinding(") + ident + ", " + lexs.back() + string(");"));
}

void Identifier::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

NumericLiteral::NumericLiteral(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void NumericLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void NumericLiteral::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void NumericLiteral::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

Literal::Literal(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void Literal::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void Literal::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void Literal::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

IdentifierReference::IdentifierReference(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void IdentifierReference::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void IdentifierReference::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void IdentifierReference::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

BindingIdentifier::BindingIdentifier(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void BindingIdentifier::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void BindingIdentifier::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void BindingIdentifier::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

PrimaryExpression::PrimaryExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void PrimaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void PrimaryExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void PrimaryExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

MemberExpression::MemberExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void MemberExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void MemberExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void MemberExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

NewExpression::NewExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void NewExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void NewExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void NewExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

LeftHandSideExpression::LeftHandSideExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void LeftHandSideExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void LeftHandSideExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void LeftHandSideExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

UpdateExpression::UpdateExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void UpdateExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void UpdateExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void UpdateExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

UnaryExpression::UnaryExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void UnaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void UnaryExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void UnaryExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

ExponentiationExpression::ExponentiationExpression(Expression *_LHS) : LHS(_LHS),
                                                                       RHS(nullptr) {
	children.push_back(LHS);
}

ExponentiationExpression::ExponentiationExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	children.push_back(RHS);
	children.push_back(LHS);
}

void ExponentiationExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ExponentiationExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto lhs = refs.back();
		refs.pop_back();
		auto rhs = refs.back();
		refs.pop_back();
		emit(string("ExponentiationOperator(" + lhs + string(", ") + rhs + string(");")));
	}
}

void ExponentiationExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS) : LHS(_LHS),
                                                                       RHS(nullptr) {
	children.push_back(LHS);
}

MultiplicativeExpression::MultiplicativeExpression(
	Expression *_LHS,
	string _OP,
	Expression *_RHS
) : LHS(_LHS),
    OP(_OP),
    RHS(_RHS) {
	children.push_back(RHS);
	children.push_back(LHS);
}

void MultiplicativeExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void MultiplicativeExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto lhs = refs.back();
		refs.pop_back();
		auto rhs = refs.back();
		refs.pop_back();
		if (OP == "*") {
			emit(string("MultiplicationOperator(") + lhs + string(", ") + rhs + string(");"));
		} else if (OP == "/") {
			emit(string("DivisionOperator(") + lhs + string(", ") + rhs + string(");"));
		} else if (OP == "%") {
			emit(string("ModulusOperator(") + lhs + string(", ") + rhs + string(");"));
		}
	}
}

void MultiplicativeExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS),
                                                           RHS(nullptr) {
	children.push_back(LHS);
}

AdditiveExpression::AdditiveExpression(Expression *_LHS,
                                       string _OP,
                                       Expression *_RHS) :
	LHS(_LHS),
	OP(_OP),
	RHS(_RHS) {
	children.push_back(RHS);
	children.push_back(LHS);
}

void AdditiveExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void AdditiveExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto lhs = refs.back();
		refs.pop_back();
		auto rhs = refs.back();
		refs.pop_back();
		if (OP == "+") {
			emit(string("AdditionOperator(" + lhs + ", " + rhs + ");"));
		} else if (OP == "-") {
			emit(string("SubtractionOperator(" + lhs + ", " + rhs + ");"));
		}
	}
}

void AdditiveExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

ShiftExpression::ShiftExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void ShiftExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ShiftExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void ShiftExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

RelationalExpression::RelationalExpression(Expression *_LHS) : LHS(_LHS),
                                                               RHS(nullptr),
                                                               op(nullptr) {
	children.push_back(LHS);
}

RelationalExpression::RelationalExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS),
                                                                                            RHS(_RHS),
                                                                                            op(_op) {
	vector<Node *> components = { LHS, RHS };
	auto container = new Container(components, "('" + string(op) + "' OP)");
	children.push_back(container);
}

void RelationalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void RelationalExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void RelationalExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

EqualityExpression::EqualityExpression(Expression *_LHS) : LHS(_LHS),
                                                           RHS(nullptr),
                                                           OP(nullptr) {
	children.push_back(LHS);
}

EqualityExpression::EqualityExpression(Expression *_LHS, string _OP, Expression *_RHS) : LHS(_LHS),
                                                                                        RHS(_RHS),
                                                                                        OP(_OP) {
	children.push_back(RHS);
	children.push_back(LHS);
}

void EqualityExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void EqualityExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto lhs = refs.back();
		refs.pop_back();
		auto rhs = refs.back();
		refs.pop_back();
		if (OP == "==") {
			emit(string("AbstractEqualityOperator(" + lhs + string(", ") + rhs + string(");")));
		} else if (OP == "!=") {
			emit(string("AbstractEqualityOperator(" + lhs + string(", ") + rhs + string(", new BooleanType(true));")));
		} else if (OP == "===") {
			emit(string("StrictEqualityOperator(" + lhs + string(", ") + rhs + string(");")));
		} else if (OP == "!==") {
			emit(string("StrictEqualityOperator(" + lhs + string(", ") + rhs + string(", new BooleanType(true));")));
		}
	}
}

void EqualityExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

BitwiseANDExpression::BitwiseANDExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void BitwiseANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void BitwiseANDExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void BitwiseANDExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

BitwiseXORExpression::BitwiseXORExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void BitwiseXORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void BitwiseXORExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void BitwiseXORExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

BitwiseORExpression::BitwiseORExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void BitwiseORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void BitwiseORExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void BitwiseORExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

LogicalANDExpression::LogicalANDExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void LogicalANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void LogicalANDExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void LogicalANDExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

LogicalORExpression::LogicalORExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void LogicalORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void LogicalORExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void LogicalORExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

ConditionalExpression::ConditionalExpression(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void ConditionalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void ConditionalExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void ConditionalExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS),
                                                                                 RHS(_RHS) {
	children.push_back(RHS);
	children.push_back(LHS);
}

AssignmentExpression::AssignmentExpression(Expression *_LHS) : LHS(_LHS),
                                                               RHS(nullptr) {
	children.push_back(LHS);
}

void AssignmentExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void AssignmentExpression::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto lhs = refs.back();
		refs.pop_back();
		auto rhs = refs.back();
		refs.pop_back();
		emit(string("SimpleAssignmentOperator(") + lhs + string(", ") + rhs + string(");"), false);
	}
}

void AssignmentExpression::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}

Initializer::Initializer(Expression *_LHS) : LHS(_LHS) {
	children.push_back(LHS);
}

void Initializer::dump(int indent) {
	if (LHS != nullptr) {
		auto message = string(typeid(*this).name()).substr(6) + ": ";
		Node::dump(message, indent);
		for (auto &i : children) {
			i->dump(indent + 1);
		}
	}
}

void Initializer::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void Initializer::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}
