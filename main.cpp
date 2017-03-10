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
			case REGEX_START: {
				puts("REGEX_START");
				break;
			}
			case TRUE: {
				puts("true");
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
