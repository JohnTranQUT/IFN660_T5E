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

void IdentifierName::genCode(int *registerNum) {
	auto name = string(LHS);
	string registerVar = "r" + std::to_string((*registerNum)++);
	string message = "auto " + registerVar + " = new StringType(\"" + name + "\");";
	string registerVar2 = "r" + std::to_string((*registerNum)++);
	string message2 = "auto " + registerVar2 + " = ResolveBinding(" + registerVar + ", r1);";
	Node::genCode(message);
	Node::genCode(message2);
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void DecimalLiteral::genCode(int *registerNum){
	string number = std::to_string(LHS);
	string registerVar = "r" + std::to_string((*registerNum)++);
	string message = "auto " + registerVar + " = new NumberType(" + number + ");";
	Node::genCode(message);
}

StringLiteral::StringLiteral(char *_LHS) : LHS(_LHS) { }

void StringLiteral::dump(int indent){
	auto message = string(typeid(*this).name()).substr(6) + ": " + string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

void StringLiteral::genCode(int * registerNum){
	auto name = string(LHS);
	string registerVar = "r" + std::to_string((*registerNum)++);
	string message = "auto " + registerVar + " = new StringType(\"" + name + "\");";
	Node::genCode(message);
}

NullLiteral::NullLiteral() { }

void NullLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
}

void NullLiteral::genCode(int *registerNum) {
	string registerVar = "r" + std::to_string((*registerNum)++);
	string message = "auto " + registerVar + " = new NullType();";
	Node::genCode(message);
}


BooleanLiteral::BooleanLiteral(bool _LHS) : LHS(_LHS) { }

void BooleanLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
}

void BooleanLiteral::genCode(int *registerNum) {
	string registerVar = "r" + std::to_string((*registerNum)++);
	if (LHS) {
		string message = "auto " + registerVar + " = new BooleanType(true);";
		Node::genCode(message);
	}else if(!LHS){
		string message = "auto " + registerVar + " = new BooleanType(false);";
		Node::genCode(message);
	}
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

void Identifier::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void NumericLiteral::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void Literal::genCode(int *registerNum) {
	for (auto &i : next) {
		i->genCode(registerNum);
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

void IdentifierReference::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void PrimaryExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void MemberExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void NewExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void LeftHandSideExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void UpdateExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void UnaryExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void ExponentiationExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
}

MultiplicativeExpression::MultiplicativeExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS), RHS(_RHS), op(_op) {
	next.push_back(LHS);
	next.push_back(RHS);
}

void MultiplicativeExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void MultiplicativeExpression::genCode(int *registerNum){
	/*for (auto &i : next) {
		i->genCode(registerNum);
	}*/
	if (RHS != nullptr && op != nullptr) {
		RHS->genCode(registerNum);
		string registerVarRHS = "r" + std::to_string((*registerNum) - 1);
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
		string registerVar = "r" + std::to_string((*registerNum)++);
		string message = "auto " + registerVar + " = Multiplicative(" + registerVarLHS + ", " + registerVarRHS + ", \"" + string(op) + "\");";
		Node::genCode(message);
	}
	else {
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
	}
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

void AdditiveExpression::genCode(int *registerNum){
	//for (auto &i : next) {
	//	i->genCode(registerNum);
	//}

	if (RHS != nullptr && op != nullptr) {
		RHS->genCode(registerNum);
		string registerVarRHS = "r" + std::to_string((*registerNum) - 1);
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
		string registerVar = "r" + std::to_string((*registerNum)++);
		if (op == "+") {
			string message = "auto " + registerVar + " = Additive(" + registerVarLHS + "," + registerVarRHS + ");";
			Node::genCode(message);
		}
		if (op == "-") {
			string message = "auto " + registerVar + " = Subtractive(" + registerVarLHS + "," + registerVarRHS + ");";
			Node::genCode(message);
		}
	}
	else {
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
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

void ShiftExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void RelationalExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void EqualityExpression::genCode(int *registerNum){
	/*
	for (auto &i : next) {
	i->genCode(registerNum);
	}
	*/
	if (RHS != nullptr) {
		RHS->genCode(registerNum);
		string registerRHS = "r" + std::to_string(*registerNum - 1);
		LHS->genCode(registerNum);
		string registerLHS = "r" + std::to_string(*registerNum - 1);
		string registerEqualityExpression = "r" + std::to_string((*registerNum)++);
		string message = "auto " + registerEqualityExpression + " = Equality(" + registerLHS + ", " + registerRHS + ", \"" + string(op) + "\");";
		Node::genCode(message);
	}
	else {
		LHS->genCode(registerNum);
		string registerLHS = "r" + std::to_string((*registerNum) - 1);
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

void BitwiseANDExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void BitwiseXORExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void BitwiseORExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void LogicalANDExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void LogicalORExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
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

void ConditionalExpression::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
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

void AssignmentExpression::genCode(int *registerNum){
	//for (auto &i : next) {
	//	i->genCode(registerNum);
	//}
	if (RHS != nullptr) {
		RHS->genCode(registerNum);
		string registerVarRHS = "r" + std::to_string((*registerNum) - 1);
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
		string registerVar = "r" + std::to_string((*registerNum)++);
		string message = "auto " + registerVar + " = Assignment(" + registerVarLHS + ", " + registerVarRHS + ");";
		Node::genCode(message);
	}
	else {
		LHS->genCode(registerNum);
		string registerVarLHS = "r" + std::to_string((*registerNum) - 1);
	}
}
