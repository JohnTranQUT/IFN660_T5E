#include <string>
#include <typeinfo>
#include <AstNode.h>
#include <AstExpression.h>

using namespace std;

IdentifierName::IdentifierName(char *_LHS) : LHS(_LHS) { }

void IdentifierName::dump(int indent) {
	auto message = string(typeid(*this).name()) + " (" + string(LHS) + ")";
	Node::dump(message, indent);
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()) + " (" + to_string(LHS) + ")";
	Node::dump(message, indent);
}

Identifier::Identifier(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void Identifier::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

NumericLiteral::NumericLiteral(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void NumericLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

Literal::Literal(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void Literal::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

IdentifierReference::IdentifierReference(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void IdentifierReference::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

PrimaryExpression::PrimaryExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void PrimaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

MemberExpression::MemberExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void MemberExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

NewExpression::NewExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void NewExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

LeftHandSideExpression::LeftHandSideExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LeftHandSideExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

UpdateExpression::UpdateExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void UpdateExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

UnaryExpression::UnaryExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void UnaryExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

ExponentiationExpression::ExponentiationExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ExponentiationExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void MultiplicativeExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void AdditiveExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

ShiftExpression::ShiftExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ShiftExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

RelationalExpression::RelationalExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void RelationalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

EqualityExpression::EqualityExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void EqualityExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

BitwiseANDExpression::BitwiseANDExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

BitwiseXORExpression::BitwiseXORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseXORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

BitwiseORExpression::BitwiseORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void BitwiseORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

LogicalANDExpression::LogicalANDExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LogicalANDExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

LogicalORExpression::LogicalORExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void LogicalORExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

ConditionalExpression::ConditionalExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

void ConditionalExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

AssignmentExpression::AssignmentExpression(Expression *_LHS, Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	next.push_back(LHS);
	next.push_back(RHS);
}

AssignmentExpression::AssignmentExpression(Expression *_LHS) : LHS(_LHS), RHS(nullptr) {
	next.push_back(LHS);
}

void AssignmentExpression::dump(int indent) {
	auto message = string(typeid(*this).name()) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}
