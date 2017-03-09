//#define _CRT_SECURE_NO_DEPRECATE 
/*Put the define here or in the properties of the project to step through security issue of VS*/
#include <stdio.h>
#include <y.tab.h>

extern FILE *yyin;

int yylex();

YYSTYPE yylval;

int main(int argc, char* argv[])
{
	int token;

	yyin = fopen(argv[1], "r");

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
		case INT:
			printf("INT\n");
			break;
		case BOOL:
			printf("BOOL\n");
			break;
			//Manh Tuan Nguyen (Jin) - 20170309
		case BREAK:		printf("BREAK\n");		break;
		case DO:		printf("DO\n");		break;
		case IN:		printf("IN\n");		break;
		case TYPEOF:		printf("TYPEOF\n");		break;
		case CASE:		printf("CASE\n");		break;
		case ELSE:		printf("ELSE\n");		break;
		case INSTANCEOF:		printf("INSTANCEOF\n");		break;
		case VAR:		printf("VAR\n");		break;
		case CATCH:		printf("CATCH\n");		break;
		case EXPORT:		printf("EXPORT\n");		break;
		case NEW:		printf("NEW\n");		break;
		case VOID:		printf("VOID\n");		break;
		case CLASS:		printf("CLASS\n");		break;
		case EXTENDS:		printf("EXTENDS\n");		break;
		case RETURN:		printf("RETURN\n");		break;
		case WHILE:		printf("WHILE\n");		break;
		case CONST:		printf("CONST\n");		break;
		case FINALLY:		printf("FINALLY\n");		break;
		case SUPER:		printf("SUPER\n");		break;
		case WITH:		printf("WITH\n");		break;
		case CONTINUE:		printf("CONTINUE\n");		break;
		case FOR:		printf("FOR\n");		break;
		case SWITCH:		printf("SWITCH\n");		break;
		case YIELD:		printf("YIELD\n");		break;
		case DEBUGGER:		printf("DEBUGGER\n");		break;
		case FUNCTION:		printf("FUNCTION\n");		break;
		case THIS:		printf("THIS\n");		break;
		case DEFAULT:		printf("DEFAULT\n");		break;
		case IF:		printf("IF\n");		break;
		case THROW:		printf("THROW\n");		break;
		case DELETE:		printf("DELETE\n");		break;
		case IMPORT:		printf("IMPORT\n");		break;
		case TRY:		printf("TRY\n");		break;
		case AWAIT:		printf("AWAIT\n");		break;
		case ENUM:		printf("ENUM\n");		break;
		case TDOT:		printf("'...'\n");		break;
		case LE:		printf("'<='\n");		break;
		case GE:		printf("'>='\n");		break;
		case EQ:		printf("'=='\n");		break;
		case DIFF:		printf("'!='\n");		break;
		case EQTYPE:		printf("'==='\n");		break;
		case DFTYPE:		printf("'!=='\n");		break;
		case INCREASE:		printf("'++'\n");		break;
		case DECREASE:		printf("'--'\n");		break;
		case LSHIFT:		printf("'<<'\n");		break;
		case RSHIFT:		printf("'>>'\n");		break;
		case URSHIFT:		printf("'>>>'\n");		break;
		case LOGAND:		printf("'&&'\n");		break;
		case LOOR:		printf("'||'\n");		break;
		case ADDASS:		printf("'+='\n");		break;
		case SUBASS:		printf("'-='\n");		break;
		case MULASS:		printf("'*='\n");		break;
		case REMASS:		printf("'%='\n");		break;
		case LSHIFTASS:		printf("'<<='\n");		break;
		case RSHIFTASS:		printf("'>>='\n");		break;
		case URSHIFTASS:		printf("'>>>='\n");		break;
		case BWANDASS:		printf("'&='\n");		break;
		case BWORASS:		printf("'|='\n");		break;
		case BWXORASS:		printf("'^='\n");		break;
		case ARROWF:		printf("'=>'\n");		break;
		case EXP:		printf("'**'\n");		break;
		case EXPASS:		printf("'**='\n");		break;
		case DIVASS:		printf("'/='\n");		break;
			//Manh Tuan Nguyen (Jin) - 20170309 end of keywords and extra punctuators
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
