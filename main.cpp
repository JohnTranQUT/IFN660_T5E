#include <stdio.h>
#include "y.tab.h"

int yylex();

YYSTYPE yylval;

extern FILE *yyin;
using namespace std;
int main(int argc, char* argv[])
{
		
	int token; 
	do
	{
		token = yylex();
		switch (token)
		{

		case STRING_L:			printf("String (%s)\n", yylval.name);			break;
		case NULL_L:			printf("NULL Literal");			break;
		case ERROR:   printf("ERROR, (%s)\n",yylval.name); break;
		case  0:
			printf("EOF\n");
			break;
		default:
			printf("'%c'\n", token);
			break;
		}
	} while (token != 0);

	return 0;
}
