#include <cstdio>
#include <y.tab.h>

int yylex();

YYSTYPE yylval;

extern FILE *yyin;

using namespace std;
void main(int argc, char *argv[]) {
	fopen_s(&yyin, argv[1], "r");
	int token;
	do {
		token = yylex();
		printf("Next Token: ");
		switch (token) {
		case TRUE: {
			printf("true \n");
			break;
		}
		case FALSE: {
			printf("false \n");
			break;
		}
		case DB_STR_CHARACTER: {
			printf("double string character (%s)\n", yylval.dbstrcharacter);
			break;
		}
		case SG_STR_CHARACTER: {
			printf("single string character(%s)\n", yylval.sgstrcharacter);
			break;
		}
		case LineContinuation: {
			printf("Line Continuation \n");
			break;
		}
		case 0: {
			printf("EOF\n");
			break;
		}
		default: {
			printf("'%c'\n", token);
			break;
		}
		}
	} while (token != 0);
}
