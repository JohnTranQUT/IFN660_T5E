#include <stdio.h>
#include <y.tab.h>
#include <iostream>
int yylex();

YYSTYPE yylval;
extern FILE *yyin;

int main(int argc, char* argv[])
{

	fopen_s(&yyin, argv[1], "r");
	int token;
	do
	{
		token = yylex();
		printf("next token: ");
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
		case TEMPLATE_LITERAL:
			printf("TEMPLATE_LITERAL (%s)\n", yylval.templateLiteral);
			break;				
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
