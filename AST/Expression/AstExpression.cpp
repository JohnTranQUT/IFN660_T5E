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

int IdentifierName::eval(int line, FILE* output) {
	fprintf(output, "auto r%i = \"%s\";\n",line,LHS);
	return line + 1;
}

DecimalLiteral::DecimalLiteral(double _LHS) : LHS(_LHS) { }

void DecimalLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + to_string(LHS) + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

int DecimalLiteral::eval(int line, FILE* output) {
	fprintf(output, "auto r%i = new NumberValue(%f);\n", line, LHS);
	line++;
	return line;
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

int Identifier::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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
int NumericLiteral::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
}

StringLiteral::StringLiteral(char *_LHS) : LHS(string(_LHS)) {
}

void StringLiteral::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": " + LHS + " (" + string(typeid(LHS).name()) + ")";
	Node::dump(message, indent);
}

int StringLiteral::eval(int line, FILE* output) {
	fprintf(output, "auto r%i = new StringValue(\"%s\");\n", line, LHS.c_str());
	line++;
	return line;
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

int Literal::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int IdentifierReference::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	fprintf(output, "auto r%i = ResolveBinding(r%i, lexEnv);\n", line , line-1);
	return line+1;
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

int PrimaryExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int MemberExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int NewExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int LeftHandSideExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int UpdateExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int UnaryExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int ExponentiationExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int MultiplicativeExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
}

AdditiveExpression::AdditiveExpression(Expression *_LHS) : LHS(_LHS) {
	next.push_back(LHS);
	RHS = nullptr;
}
AdditiveExpression::AdditiveExpression(Expression *_LHS, Expression *_RHS, char *_op) : LHS(_LHS),RHS(_RHS),op(_op) {
	vector<Node *> components = { LHS, RHS };
	auto container = new Container(components, "('" + string(op) + "' OP)");
	next.push_back(container);
}

void AdditiveExpression::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int AdditiveExpression::eval(int line, FILE* output) {
	if (RHS) {
		int RHSLine = RHS->eval(line, output);
		int LHSLine = LHS->eval(RHSLine,output);
		fprintf(output, "auto r%i = addition(r%i,r%i);\n",LHSLine, LHSLine-1, RHSLine-1);
		return LHSLine+1;
	}
	return LHS->eval(line, output);
	
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

int ShiftExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

//just passing the nodes belong to this expression, not implemented the relational expression
int RelationalExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

//just passing the nodes belong to this expression, not implemented the equality expression
int EqualityExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int BitwiseANDExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int BitwiseXORExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int BitwiseORExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int LogicalANDExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int LogicalORExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int ConditionalExpression::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int AssignmentExpression::eval(int line, FILE* output) {
	int LHSLine;
	if (RHS)
	{
		int RHSLine = RHS->eval(line, output);
		LHSLine = LHS->eval(RHSLine, output);
		fprintf(output, "auto r%i = assignment(r%i, r%i);\n", LHSLine, LHSLine - 1, RHSLine-1);
		return LHSLine + 1;
	}
	return LHS->eval(line, output);
}