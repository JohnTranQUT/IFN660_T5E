#include <cstdio>
#include <ast.h>

Identifier::Identifier(char* _identifier) {
	identifier = _identifier;
}

DecimalLiteral::DecimalLiteral(int _decimalLiteral) {
	decimalLiteral = _decimalLiteral;
}

AssignmentExpression::AssignmentExpression(Identifier _identifier, DecimalLiteral _decimalLiteral) {
	identifier = _identifier;
	decimalLiteral = _decimalLiteral;
}

ExpressionStatement::ExpressionStatement(AssignmentExpression _assignmentExpression) {
	assignmentExpression = _assignmentExpression;
}

Script::Script(ExpressionStatement _expressionStatement) {
	expressionStatement = _expressionStatement;
}

