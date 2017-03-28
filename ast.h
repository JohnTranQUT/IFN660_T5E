#pragma once
#include <cstdio>

class Identifier {
private:
	char* identifier;
public:
	Identifier(): identifier(nullptr) { } ;
	explicit Identifier(char*);
};

class DecimalLiteral {
private:
	int decimalLiteral;
public:
	DecimalLiteral(): decimalLiteral(0) { } ;
	explicit DecimalLiteral(int);
};

class AssignmentExpression {
private:
	Identifier identifier;
	DecimalLiteral decimalLiteral;
public:
	AssignmentExpression() { }
	AssignmentExpression(Identifier, DecimalLiteral);
};

class ExpressionStatement {
private:
	AssignmentExpression assignmentExpression;
public:
	ExpressionStatement() { }
	explicit ExpressionStatement(AssignmentExpression);
};

class Script {
private:
	ExpressionStatement expressionStatement;
public:
	Script() { }
	explicit Script(ExpressionStatement);
};
