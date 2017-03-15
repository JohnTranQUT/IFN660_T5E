#include <stdio.h>
#include <y.tab.h>

int yylex();

YYSTYPE yylval;

extern FILE *yyin;
using namespace std;
int main(int argc, char* argv[])
{
	fopen_s(&yyin, argv[1], "r");

	int token;
	do
	{
		token = yylex();
		printf("Next Token: ");
		switch (token)
		{
		case NUMBER:
			printf("NUMBER (%d)\n", yylval.num);
			break;
		case IDENT:
			printf("IDENT (%s)\n", yylval.name);
			break;
		case IF:
			printf("IF\n");
			break;
		case ELSE:
			printf("ELSE\n");
			break;
		case INT:
			printf("INT\n");
			break;
		case BOOL:
			printf("BOOL\n");
			break;
			//John Tran n9301836 Numeric Literal
		case DECIMAL:			printf("NUMBER DECIMAL (%f)\n", yylval.num);			break;
		case INTEGER:			printf("NUMBER INTEGER (%d)\n", yylval.integer);			break;
		case BINARYSTART:			printf("NUMBER BINARY START (%s)\n", yylval.name);			break;
		case BINARY:			printf("NUMBER BINARY (%f)\n", yylval.num);			break;
		case OCTAL:			printf("NUMBER OCTAL (%f)\n", yylval.num);			break;
		case HEXIDECIMAL:			printf("NUMBER HEXIDECIMAL (%f)\n", yylval.num);			break;
			//John Tran n9301836 LINE TERMINATORS
		case LINE_TERM:			printf("LINE TERMINATOR\n");			break;
			//John Tran n9301836 COMMENTS
		case COMMENT:			printf("COMMENT (%s)\n", yylval.name);			break;
		case TEST:			printf("TEST (%s)\n", yylval.name);			break;
		case 0:
			printf("EOF\n");
			break;
		default:
			printf("'%c'\n", token);
			break;
		}
	} while (token != 0);

	return 0;
}
