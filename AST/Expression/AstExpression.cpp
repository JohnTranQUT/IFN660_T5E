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

void IdentifierName::genCode(bool OnlyPrimitive) {
	Node::genCode(string("new StringType(\"") + LHS + string("\")"));
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void DecimalLiteral::genCode(bool OnlyPrimitive) {
	Node::genCode(string("new NumberType(") + to_string(LHS) + string(")"));
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

void Identifier::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
	if (!OnlyPrimitive) {
		auto ident = refs.back();
		refs.pop_back();

		Node::genCode(string("ResolveBinding(") + ident + ", " + lexs.back() + string(")"));
	}
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

void NumericLiteral::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void Literal::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void IdentifierReference::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
}

BindingIdentifier::BindingIdentifier(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BindingIdentifier::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void BindingIdentifier::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void PrimaryExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void MemberExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void NewExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void LeftHandSideExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void UpdateExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void UnaryExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void ExponentiationExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void MultiplicativeExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS),
                                                           RHS(nullptr) {
	next.push_back(LHS);
}

AdditiveExpression::AdditiveExpression(Expression *_LHS,
                                       string _OP,
                                       Expression *_RHS) :
	LHS(_LHS),
	OP(_OP),
	RHS(_RHS) {
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

void AdditiveExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
	if (next.size() > 1) {
		if (OP == "+") {
			auto lhs = refs.back();
			refs.pop_back();
			auto rhs = refs.back();
			refs.pop_back();
			Node::genCode(string("AdditionOperator(" + lhs + ", " + rhs + ")"));
		}
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

void ShiftExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
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

void RelationalExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
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

void EqualityExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void BitwiseANDExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void BitwiseXORExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void BitwiseORExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void LogicalANDExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void LogicalORExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
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

void ConditionalExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS),
                                                                                 RHS(_RHS) {
	next.push_back(RHS);
	next.push_back(LHS);
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

void AssignmentExpression::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
	if (!OnlyPrimitive) {
		if (next.size() > 1) {
			auto lhs = refs.back();
			refs.pop_back();
			auto rhs = refs.back();
			refs.pop_back();
			Node::genCode(string("SimpleAssignmentOperator(") + lhs + string(", ") + rhs + string(")"), false);
		}
	}
}

Initializer::Initializer(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void Initializer::dump(int indent) {
	if (LHS != nullptr) {
		auto message = string(typeid(*this).name()).substr(6) + ": ";
		Node::dump(message, indent);
		for (auto &i : next) {
			i->dump(indent + 1);
		}
	}
}

void Initializer::genCode(bool OnlyPrimitive) {
	for (auto &i : next) {
		i->genCode(OnlyPrimitive);
	}
}
