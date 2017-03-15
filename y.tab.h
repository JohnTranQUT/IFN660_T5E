#pragma once

enum yytokentype
{
	STRING_L = 264,
	NULL_L = 265,
	ERROR = 999
};
typedef union YYSTYPE
{
	char* name;
};
extern YYSTYPE yylval;
