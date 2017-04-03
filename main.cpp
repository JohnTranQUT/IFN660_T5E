#include <cstdio>
#include <ast.h>
#include <parser.h>

extern FILE *yyin;

using namespace std;

void main(int argc, char *argv[]) {
	char *IDENT = "x";
	double DECIMAL = 42;

	auto identifier = new Identifier(IDENT);
	auto decimalLiteral = new DecimalLiteral(DECIMAL);

	auto assignmentExpression = new AssignmentExpression(identifier, decimalLiteral);
	auto expression = new Expression(assignmentExpression);
	auto expressionStatement = new ExpressionStatement(expression);
	auto statement = new Statement(expressionStatement);
	auto script = new Script(statement);

	script->dump();

	fopen_s(&yyin, argv[1], "r");
	yyparse();
}
