#include <typeinfo>
#include <AST/Node/AstNode.h>
#include <AST/Expression/AstExpression.h>
#include <AST/Statement/AstStatement.h>
#include <AST/Script/AstScript.h>
using namespace std;

BlockStatement::BlockStatement(Statement *_statement) : statement(_statement) {
	next.push_back(statement);
}

void BlockStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void BlockStatement::genCode(int *registerNum) {
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}

Block::Block(StatementList *_statementlist) : statementlist(_statementlist) {
	next.push_back(statementlist);
}

void Block::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void Block::genCode(int *registerNum) {
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}

ExpressionStatement::ExpressionStatement(Expression *_expression) : expression(_expression) {
	next.push_back(expression);
}

void ExpressionStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void ExpressionStatement::genCode(int *registerNum){
	for (auto &i : next) {
		i->genCode(registerNum);
	}
}

IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement, Statement *_elseStatement) : expression(_expression),
                                                                                                        ifStatement(_ifStatement),
                                                                                                        elseStatement(_elseStatement) {
	vector<Node*> expComp = { expression };
	vector<Node*> ifComp = { ifStatement };
	vector<Node*> elseComp = { elseStatement };
	auto expCont = new Container(expComp, "(CONDITIONS)");
	auto ifCont = new Container(ifComp, "(IF)");
	auto elseCont = new Container(elseComp, "(ELSE)");
	next.push_back(expCont);
	next.push_back(ifCont);
	next.push_back(elseCont);
}

IfStatement::IfStatement(Expression *_expression, Statement *_ifStatement) : expression(_expression),
                                                                             ifStatement(_ifStatement),
                                                                             elseStatement(nullptr) {
	next.push_back(expression);
	next.push_back(ifStatement);
}

void IfStatement::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void IfStatement::genCode(int *registerNum){
	expression->genCode(registerNum);
	string registerExpression = "r" + std::to_string(*registerNum - 1);
	ifStatement->genCode(registerNum);
	string registerIfStatement = "r" + std::to_string(*registerNum - 1);
	if(elseStatement!=nullptr){
		elseStatement->genCode(registerNum);
		string registerElseStatement = "r" + std::to_string(*registerNum - 1);
		string registerIf = "r" + std::to_string((*registerNum)++);
		string message = "auto " + registerIf + " = new ifstatementeval(" + registerExpression + ", " + registerIfStatement + ",r" + registerElseStatement + ");";
		Node::genCode(message);
	}
	else {
		string registerIf = "r" + std::to_string((*registerNum)++);
		string message = "auto " + registerIf + " = new ifstatementeval(" + registerExpression + ", " + registerIfStatement + ");";
		Node::genCode(message);
	}
	/*
	for (auto &i : next) {
		i->genCode(registerNum);
	}
	*/
}

