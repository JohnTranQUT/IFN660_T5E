#include <cstdio>
#include <ast.h>

using namespace std;

Identifier::Identifier(char *_identifier) {
	identifier = _identifier;
}

void Identifier::dump() {
	printf("Identifier (%s)\n", identifier);
}

DecimalLiteral::DecimalLiteral(double _decimalLiteral) {
	decimalLiteral = _decimalLiteral;
}

void DecimalLiteral::dump() {
	printf("Decimal Literal (%f)\n", decimalLiteral);
}

AssignmentExpression::AssignmentExpression(Identifier* _identifier, DecimalLiteral* _decimalLiteral) {
	identifier = _identifier;
	decimalLiteral = _decimalLiteral;
}

void AssignmentExpression::dump() {
	puts("AssignmentExpression: ");
}

ExpressionStatement::ExpressionStatement(AssignmentExpression *_assignmentExpression) {
	assignmentExpression = _assignmentExpression;
}

void ExpressionStatement::dump() {
	puts("ExpressionStatement: ");
}

Statement::Statement(ExpressionStatement *_expressionStatement) {
	expressionStatement = _expressionStatement;
}

void Statement::dump() {
	puts("Statement: ");
}

Script::Script(Statement *_statement) {
	statement = _statement;
}

void Script::dump() {
	puts("Script: ");
}
