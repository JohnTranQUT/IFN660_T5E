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
				printf("REGEX_START (%s)\n", yylval.regexStart);
				break;
			}
			case REGEX_END: {
				printf("REGEX_END (%s)\n", yylval.regexEnd);
				break;
			}
			case REGEX_FLAGS: {
				printf("REGEX_FLAGS (%s)\n", yylval.regexFlags);
				break;
			}
			case REGEX_BODY: {
				printf("REGEX_BODY (%s)\n", yylval.regexBody);
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
