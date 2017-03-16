#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <y.tab.h>

int yylex();
YYSTYPE yylval;
extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
	int token;
	yyin = fopen(argv[1], "r");
	do {
		token = yylex();
		printf("Next Token: ");
		switch (token) {

			// JOHN - START

			case DECIMAL:
				printf("NUMBER DECIMAL (%f)\n", yylval.num);
				break;
			case INTEGER:
				printf("NUMBER INTEGER (%d)\n", yylval.integer);
				break;
			case BINARYSTART:
				printf("NUMBER BINARY START (%s)\n", yylval.name);
				break;
			case BINARY:
				printf("NUMBER BINARY (%f)\n", yylval.num);
				break;
			case OCTAL:
				printf("NUMBER OCTAL (%f)\n", yylval.num);
				break;
			case HEXIDECIMAL:
				printf("NUMBER HEXIDECIMAL (%f)\n", yylval.num);
				break;
			case LINE_TERM:
				printf("LINE TERMINATOR\n");
				break;
			case COMMENT:
				printf("COMMENT (%s)\n", yylval.name);
				break;
			case TEST:
				printf("TEST (%s)\n", yylval.name);
				break;

			// JOHN - END

			// MICHAEL - START -------------------------------------------------------

			case STRING_L:
				printf("String (%s)\n", yylval.name);
				break;
			case NULL_L:
				printf("NULL Literal");
				break;
			case ERROR:
				printf("ERROR, (%s)\n", yylval.name);
				break;

			// MICHAEL - END -------------------------------------------------------

			// ALFRED - START -------------------------------------------------------

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

			// ALFRED - END -------------------------------------------------------

			// JASON - START -------------------------------------------------------

			case TEMPLATE_LITERAL:
				printf("TEMPLATE_LITERAL (%s)\n", yylval.templateLiteral);
				break;

			// JASON - END -------------------------------------------------------

			// JIN - START -------------------------------------------------------

			case BREAK: puts("BREAK");
				break;
			case DO: puts("DO");
				break;
			case IN: puts("IN");
				break;
			case TYPEOF: puts("TYPEOF");
				break;
			case CASE: puts("CASE");
				break;
			case ELSE: puts("ELSE");
				break;
			case INSTANCEOF: puts("INSTANCEOF");
				break;
			case VAR: puts("VAR");
				break;
			case CATCH: puts("CATCH");
				break;
			case EXPORT: puts("EXPORT");
				break;
			case NEW: puts("NEW");
				break;
			case VOID: puts("VOID");
				break;
			case CLASS: puts("CLASS");
				break;
			case EXTENDS: puts("EXTENDS");
				break;
			case RETURN: puts("RETURN");
				break;
			case WHILE: puts("WHILE");
				break;
			case CONST: puts("CONST");
				break;
			case FINALLY: puts("FINALLY");
				break;
			case SUPER: puts("SUPER");
				break;
			case WITH: puts("WITH");
				break;
			case CONTINUE: puts("CONTINUE");
				break;
			case FOR: puts("FOR");
				break;
			case SWITCH: puts("SWITCH");
				break;
			case YIELD: puts("YIELD");
				break;
			case DEBUGGER: puts("DEBUGGER");
				break;
			case FUNCTION: puts("FUNCTION");
				break;
			case THIS: puts("THIS");
				break;
			case DEFAULT: puts("DEFAULT");
				break;
			case IF: puts("IF");
				break;
			case THROW: puts("THROW");
				break;
			case DELETE: puts("DELETE");
				break;
			case IMPORT: puts("IMPORT");
				break;
			case TRY: puts("TRY");
				break;
			case AWAIT: puts("AWAIT");
				break;
			case ENUM: puts("ENUM");
				break;
			case TDOT: puts("'...'");
				break;
			case LE: puts("'<='");
				break;
			case GE: puts("'>='");
				break;
			case EQ: puts("'=='");
				break;
			case DIFF: puts("'!='");
				break;
			case EQTYPE: puts("'==='");
				break;
			case DFTYPE: puts("'!=='");
				break;
			case INCREASE: puts("'++'");
				break;
			case DECREASE: puts("'--'");
				break;
			case LSHIFT: puts("'<<'");
				break;
			case RSHIFT: puts("'>>'");
				break;
			case URSHIFT: puts("'>>>'");
				break;
			case LOGAND: puts("'&&'");
				break;
			case LOOR: puts("'||'");
				break;
			case ADDASS: puts("'+='");
				break;
			case SUBASS: puts("'-='");
				break;
			case MULASS: puts("'*='");
				break;
			case REMASS: puts("'%='");
				break;
			case LSHIFTASS: puts("'<<='");
				break;
			case RSHIFTASS: puts("'>>='");
				break;
			case URSHIFTASS: puts("'>>>='");
				break;
			case BWANDASS: puts("'&='");
				break;
			case BWORASS: puts("'|='");
				break;
			case BWXORASS: puts("'^='");
				break;
			case ARROWF: puts("'=>'");
				break;
			case EXP: puts("'**'");
				break;
			case EXPASS: puts("'**='");
				break;
			case DIVASS: puts("'/='");
				break;

			// JIN - END -------------------------------------------------------

			case 0:
				puts("EOF");
				break;
			default:
				printf("'%c'\n", token);
				break;
		}
	} while (token != 0);
}
