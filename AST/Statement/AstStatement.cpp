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

int BlockStatement::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int Block::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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

int ExpressionStatement::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
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


int IfStatement::eval(int line, FILE* output) {
	line = next[0]->eval(line, output);
	fprintf(output, "if (r%d) {\n", line-1);
	line = next[1]->eval(line, output);
	fprintf(output, "}\n");
	if (next.size() > 2)
	{
		fprintf(output, "else {\n");
		line = next[1]->eval(line, output);
		fprintf(output, "}\n");
	}
	return line;
}
