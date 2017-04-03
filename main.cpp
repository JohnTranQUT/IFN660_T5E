#include <cstdio>
#include <ast.h>
//#include <parser.h>

//extern FILE *yyin;

using namespace std;
void main(int argc, char *argv[]) {
//	fopen_s(&yyin, argv[1], "r");	
//	yyparse();
	char* IDENT = "x";
	double DECIMAL = 42;

	auto identifier = new Identifier(IDENT);
	auto decimalLiteral = new DecimalLiteral(DECIMAL);

	auto assignmentExpression = new AssignmentExpression(identifier, decimalLiteral);
	auto expressionStatement = new ExpressionStatement(assignmentExpression);
	auto statement = new Statement(expressionStatement);
	auto script = new Script(statement);

	script->dump();
}
